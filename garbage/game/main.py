import pygame
import random
import math
import os
pygame.init()

size = 100
ratio = [16,9]
# wid = ratio[0]*size
# hei = ratio[1]*size
info = pygame.display.Info()
wid = int(info.current_w)
hei = int(info.current_h)
screen = pygame.display.set_mode((wid, hei), pygame.FULLSCREEN)
player_sizey = 40
player_x = 200
player_y = hei/2-player_sizey/2
y_vel = 0
GAMESPEED = 14
bgspawn = hei-1
bgs = []
canvasList = []
# for i in range(0, 3):
#     bgs.append(Bg((i*hei)-size*4, 0))
boosters = [False,#2ray
            False,#3ray
            False,#1hench
            False,#2hench
            False]#3hench
enemy_bullet = []
invaders = []
stars = []
slowstars = []
exhaust = []
particles = []
booster = []
shooting = False
game = True
game_state = "home"
clock = pygame.time.Clock()
timer = 0
spawn_time = 0
blink = 0
score = 0
sc=0
kills = 0
ki=0
player_death_timer  =0
cooldown = False
cooldown_counter = 0
cooldown_timer = 0
healthbar = {1:"0", 2:"0 0", 3:"0 0 0"}
difficulty = "dont hurt me"
spawnrate = 30
star_time = 0



def render_text(string, x,y, col, size, font = "snapitc"):
    pygame.font.init()
    font = pygame.font.SysFont(font, size, )
    text = font.render(string, True, col)
    screen.blit(text, [x,y])

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))
shpath = os.path.join(SCRIPT_DIR, "ship.png")
enpath = os.path.join(SCRIPT_DIR, "enemy.png")
en2path = os.path.join(SCRIPT_DIR, "enemy2.png")
en3path = os.path.join(SCRIPT_DIR, "enemy3.png")
en4path = os.path.join(SCRIPT_DIR, "enemy4.png")
en5path = os.path.join(SCRIPT_DIR, "enemy5.png")
en6path = os.path.join(SCRIPT_DIR, "enemy6.png")
bgpath = os.path.join(SCRIPT_DIR, "bg.png")
bullpath = os.path.join(SCRIPT_DIR, "bullet.png")
bull2path = os.path.join(SCRIPT_DIR, "bullet2.png")

bg2path = os.path.join(SCRIPT_DIR, "bg2.png")
bg3path = os.path.join(SCRIPT_DIR, "bg3.png")

ship = pygame.image.load(shpath).convert_alpha()
ship = pygame.transform.scale(ship, (120,90))
bullet = pygame.image.load(bullpath).convert_alpha()
bullet = pygame.transform.scale(bullet, (100,30))

bullet2 = pygame.image.load(bull2path).convert_alpha()
bullet2 = pygame.transform.scale(bullet2, (100,30))

bg1 = pygame.image.load(bgpath).convert_alpha()
bg1 = pygame.transform.scale(bg1, (hei,hei))

bg2 = pygame.image.load(bg2path).convert_alpha()
bg2 = pygame.transform.scale(bg2, (hei,hei))

bg3 = pygame.image.load(bg3path).convert_alpha()
bg3 = pygame.transform.scale(bg3, (hei,hei))

enemy = pygame.image.load(enpath).convert_alpha()
enemy = pygame.transform.scale(enemy, (100,70))

enemy2 = pygame.image.load(en2path).convert_alpha()
enemy2 = pygame.transform.scale(enemy2, (100,70))

enemy3 = pygame.image.load(en3path).convert_alpha()
enemy3 = pygame.transform.scale(enemy3, (100,70))

enemy4 = pygame.image.load(en4path).convert_alpha()
enemy4 = pygame.transform.scale(enemy4, (100,70))

enemy5 = pygame.image.load(en5path).convert_alpha()
enemy5 = pygame.transform.scale(enemy5, (100,70))

enemy6 = pygame.image.load(en6path).convert_alpha()
enemy6 = pygame.transform.scale(enemy6, (100,70))
random_bg = [bg1, bg2, bg3]
bg = random_bg[random.randint(0, len(random_bg)-1)]
enemies = [enemy, enemy2,enemy3,enemy4,enemy5,enemy6]
player_health = 3
class Bg:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def render(self, speed):
        self.x -= speed
        screen.blit(bg, (self.x, self.y))
class particle:
    def __init__(self, x, y,speed, eff):
        self.x = x
        self.y = y
        self.speed = speed
        self.eff = eff
    def render(self):
        self.x -= self.speed
        pygame.draw.rect(screen, (255,int(self.x/2) ,0), [self.x, self.y-(9/100)*self.x*self.eff, 15,20+(self.x*(5/100))*self.eff])

class Booster_entity:
    def __init__(self, x, y):
        
        self.x = x
        self.y = y
        self.entity = pygame.draw.ellipse(screen,(0,0,255), [self.x, self.y, 36,36],width = 3)
        
        
    def spawn(self):
        self.x-=GAMESPEED/2
        self.entity = pygame.draw.ellipse(screen,(0,0,255), [self.x, self.y, 36,36],width = 3)
        
        

        




class Dparticle:
    def __init__(self, x,y,sizex, sizey, speedx, speedy):
        self.x=x
        self.y=y
        self.sizex = sizex
        self.sizey = sizey
        self.speedx = speedx
        self.speedy = speedy
        self.col = (255,random.randint(0,255) ,0)
    def render(self):
        self.x += self.speedx
        self.y += self.speedy
        self.speedx -= GAMESPEED/20
        pygame.draw.ellipse(screen, self.col, [self.x, self.y, self.sizex,self.sizey])

class Star():
    def __init__(self,x,y):
        self.x = x
        self.y=y
        self.size = random.randint(1,3)    
    def show(self, speed):
        pygame.draw.rect(screen, (255,255,255), [self.x, self.y, self.size,self.size])
        self.x -= speed

class Bullet():
    def __init__(self, x,y, col, image=1):
        self.x = x
        self.y = y
        self.sprite = pygame.Rect(self.x-10+70, (self.y+player_sizey/2)+25, 100,30)
        self.col = col
        self.image = image
    def shoot(self, speedx, speedy):
        self.x += speedx
        self.y += speedy
        if self.image == 1:
            self.sp = screen.blit(bullet, (self.x-10+70, (self.y+player_sizey/2)+25))
        else:self.sp = screen.blit(bullet2, (self.x-10+70, (self.y+player_sizey/2)+25))
        self.sprite = pygame.Rect(self.x-10+70, (self.y+player_sizey/2)+25, 100,30)

class Invador():
    def __init__(self,x,y, health, speedx = 0, speedy = 0):
        self.pi = 0
        self.x = x
        self.xspeed = 9#random.randint(int(GAMESPEED+GAMESPEED*(66/100)),int(GAMESPEED*2+GAMESPEED/3))
        self.y = y#*random.randint(0, int(hei/100))
        self.health = health
        if player.booster_status>=1:
            self.health += 300
        if player.booster_status >=3:
            self.health +=300
        self.col = (random.randint(150,255),random.randint(150,255),random.randint(150,255), 255)
        self.timer = random.randint(50,200) 
        self.time = random.randint(100,300) 
        self.image = enemies[random.randint(0, len(enemies)-1)]
        self.destroy_time = 0
        self.particle_time = 0
        self.is_sin = random.randint(0,0)
        self.exh = []
        self.r = random.randint(1,10)
        self.health_indicator = self.health

        # move initialisation\
    def move(self,speedx, speedy):
        self.x += speedx
        self.y += speedy
    
         

    def spawn(self,y, memberlist, memberobj,bulletarr):
        self.x -= self.xspeed
        self.y += y
        self.pi +=0.1
        self.y+= self.is_sin*(+5*math.sin(self.pi))
        if self.health>=0:
            pygame.draw.rect(screen, (255,0,0), [self.x-self.health_indicator*2/100, self.y-13, self.health*(20/100), 7])  
            pygame.draw.rect(screen, (255,255,255), [self.x-self.health_indicator*2/100, self.y-13, self.health_indicator*(20/100)+2, 9],width = 1)
        self.ent = screen.blit(self.image, (self.x, self.y))
        for obj in player.bullets[:]:
            if self.ent.colliderect(obj.sprite):
                player.bullets.remove(obj)
                self.health -= 60
        if self.ent.colliderect(player.entity):
            if not cooldown:
                self.health = 0
        self.timer += 1
        
        if self.health<=0:
            self.xspeed = 0
            self.image = pygame.transform.scale(self.image, (10,10))
            canvasList.append(Dparticle(self.x+45, self.y+30, 10,10,random.randint(-1,1),random.randint(-1,1)))
            self.particle_time +=1
            if self.particle_time>= 10:
                particles.pop()
            self.destroy_time +=GAMESPEED/3
            if self.destroy_time>=40:
                self.destroy_time = 0
                if self.r== 2:
                    if player.booster_status<5:
                        booster.append(Booster_entity(self.x,self.y))
                try:
                    memberlist.remove(memberobj) 
                    
                except Exception  as e:...
        if difficulty =="bring em on" or difficulty =="fry their flesh":
            if self.timer >= self.time:
                self.timer = 0
                if self.health >0:
                    bulletarr.append(Bullet(self.x, self.y, (255,0,0), image = 2))


class Henchman:
    def __init__(self,  health, bullet_container):
        self.x = 0
        self.y = 0
        self.phase = 0
        self.is_shooting = False
        self.entity = None
        self.bullets = bullet_container
        self.shoot_timer = 0
        self.cooldown = 3
        self.i = 0
    def spwan(self, x, y, phase, is_shooting):
        self.i += GAMESPEED/50
        self.x = x
        self.y = y
        self.phase = phase
        self.y += math.sin((self.i/3)+self.phase)*150
        self.x +=math.cos((self.i/3)+self.phase)*150
        self.is_shooting = is_shooting
        self.entity = pygame.draw.ellipse(screen, (0, 255,0), [self.x, self.y, 36,36], width=3)
        if self.is_shooting:
            self.shoot_timer += GAMESPEED/6
            if self.shoot_timer >= self.cooldown-1:
                self.shoot_timer = 0
                self.bullets.append(Bullet(self.x-70, self.y-40, (0,0,0)))

       
    
        
class Player:
    def __init__(self):
        self.acquired_boosters = []
        
        self.bullets = []
        self.x = 0
        self.y = 0
        self.health = 0
        self.is_shooting = False
        self.entity = None
        self.shoot_timer = 0
        self.cooldown = 6
        self.i = 0
        self.hench = Henchman( 3, self.bullets)
        self.hench2 = Henchman( 3, self.bullets)
        
        self.hench3 = Henchman(3, self.bullets)
        
    def spwan(self,x,y, is_shooting, health):
        self.health = health
        self.hench2.i = self.hench.i
        self.hench3.i  = self.hench2.i
        self.booster_status = len(self.acquired_boosters)
        particles.append(Dparticle(self.x, self.y+50, 5,5, random.randint(-1,1),random.randint(-1,1)))
            
        self.x = x
        self.y = y
        self.i +=GAMESPEED/50
        self.y += math.sin(self.i)*3
        self.is_shooting =  is_shooting
        self.shoot_timer +=GAMESPEED/6
        if self.shoot_timer >= self.cooldown:
            self.shoot_timer = 0
        
        self.entity = screen.blit(ship, (self.x, self.y))
        if self.is_shooting:
            if self.health >=1:
                if self.shoot_timer >= self.cooldown-1:
                    self.bullets.append(Bullet(self.x, self.y, (0,0,0)))
                    if self.booster_status >=1:
                        self.bullets.append(Bullet(self.x, self.y-20, (0,0,0)))
                    if self.booster_status >=2:
                        self.bullets.append(Bullet(self.x, self.y-40, (0,0,0)))
        for b in player.bullets[:]:
            b.shoot(GAMESPEED*5, 0)   
            if b.x >= wid:
                player.bullets.remove(b) 
                
        for bo in booster[:]:
            bo.spawn()
            if self.entity.colliderect(bo.entity):
                self.acquired_boosters.append(f"acquired booster {self.booster_status}")
                booster.remove(bo)
        if self.booster_status >= 3:
                
                self.hench.spwan(player_x+60, player_y+35,0, shooting)
        if self.booster_status >= 4:
                
                self.hench2.spwan(player_x+60, player_y+35,math.pi*4/6, shooting)
        if self.booster_status >= 5:
                
                self.hench3.spwan(player_x+60, player_y+35,2*math.pi-math.pi*4/6, shooting)      
        render_text("BOOSTERS: ", 200, 30, (255,100,60), 24, "null") 
        pygame.draw.rect(screen, (100, 100,100),[298, 30, 95, 14])
        pygame.draw.rect(screen, (255, 100,100),[298, 30, 95, 14],width=2)
        for i in range(0, len(self.acquired_boosters)):
            pygame.draw.rect(screen, (0, 255, 0), [300+20*i, 32, 10,10 ])
                    
        
player = Player()
random_wave = ["diagonal", "v shape", "spiral"]
wave_index = 0
def waveSpawning(wave_no,wave_type):
     
    if wave_type == "diagonal":
        for j in range(1, wave_no+1):
            for i in range(0, 10):
                invaders.append(Invador(wid+50*i+140*j, 100+70*i, 200))
        
    elif wave_type == "v shape":
        for l in range(1, wave_no+1):
            for i in range(0, 3):
                invaders.append(Invador((wid+50*i)+140*l, 100+80*i, 200))
            for k in range(-3, 1):
                invaders.append(Invador((wid-50*k)+140*l, 100+80*(i+(i+k)+2), 200))
    elif wave_type == "spiral":
        x = -5
        y = 5
        r = random.randint(3,6)
        for m in range(1,12):
            sinx = x+math.sin(math.pi*m/6)*r
            cosy = y+math.cos(math.pi*m/6)*r
            invaders.append(Invador(wid-sinx*70, 100+cosy*70, 200))

    
        
        



while game:
    
    
    clock.tick(60)
    screen.fill((20,20,20))
    
    
    bgspawn += GAMESPEED/3
    if bgspawn >= hei:
        bgspawn = 0
        for i in range(0,4):
            canvasList.append(Bg(i*hei, 0))
    # for b in canvasList[:]:
    #     if isinstance(b, Bg):
    #         b.render(GAMESPEED/3)
    #         if b.x <= -hei:
    #             canvasList.remove(b)
    blink +=GAMESPEED/3          
    if blink >= 100:
        blink = 0
    for i in range(0, wid):
        slowstars.append(Star(i*8, random.randint(0,hei)))
        stars.append(Star(i*8, random.randint(0,hei)))
        if len(stars)>=150:
            stars.pop()
            slowstars.pop()
    star_time+=GAMESPEED/3
    if star_time>=5:
        star_time = 0 
        stars.append(Star(wid, random.randint(0,hei)))
        slowstars.append(Star(wid, random.randint(0,hei)))
    for s in stars[:]:
        s.show(GAMESPEED+GAMESPEED/3)
        if s.x <= -200:
            stars.remove(s)
        if len(stars)>=700:
            stars.pop()
    for s in slowstars[:]:
        s.show(GAMESPEED-GAMESPEED/3)
        if s.x <= -200:
            slowstars.remove(s)
        if len(stars)>=700:
            stars.pop()
    for p in canvasList[:]:
            if isinstance(p, Dparticle):
                p.render()
                if p.x<=0:
                    canvasList.remove(p)
    mousepos = pygame.mouse.get_pos()
    if game_state == "difficulty":
        GAMESPEED = 6
        score = 0
        kills = 0
        if blink>= 50:render_text("Choose difficulty", (wid/2)-300,(hei/2)-100, (255,0,0), 60)
        a = pygame.Rect((wid/2)-140,(hei/2), 300, 30)
        b = pygame.Rect((wid/2)-140,(hei/2)+40, 300, 30)
        c = pygame.Rect((wid/2)-140,(hei/2)+80, 300, 30)
        render_text("0 Bring Em On!", (wid/2)-140,(hei/2)+40, (255,0,0), 30)
        render_text("0 Fry Their Flesh!!", (wid/2)-140,(hei/2)+80, (255,0,0), 30)
        render_text("0 Don't Hurt Me", (wid/2)-140,(hei/2), (255,0,0), 30)
        if a.collidepoint(mousepos):render_text("0 Don't Hurt Me", (wid/2)-140,(hei/2), (255,255,0), 30)
        elif b.collidepoint(mousepos):render_text("0 Bring Em On!", (wid/2)-140,(hei/2)+40, (255,255,0), 30)
        elif c.collidepoint(mousepos):render_text("0 Fry Their Flesh!!", (wid/2)-140,(hei/2)+80, (255,255,0), 30)
    for event in pygame.event.get():
        if event.type == pygame.MOUSEBUTTONDOWN:
            if event.button == 1:
                shooting = True
                if game_state !="game":
                    game_state = "difficulty"
                try:
                    if a.collidepoint(mousepos):
                        difficulty = "dont hurt me"
                        game_state = "game"
                    elif b.collidepoint(mousepos):
                        difficulty = "bring em on"
                        game_state = "game"
                    elif c.collidepoint(mousepos):
                        difficulty = "fry their flesh"
                        game_state = "game"
                except Exception as e:...
        if event.type == pygame.MOUSEMOTION:
            if shooting:
                player_y = event.pos[1]
        if event.type == pygame.QUIT:
            game = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE:
                game = False
            if event.key == pygame.K_UP:
                y_vel = -5
            if event.key == pygame.K_SPACE:
                shooting = True
                if game_state !="game":
                    game_state = "difficulty"
            if event.key == pygame.K_DOWN:
                y_vel = 5
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_UP:
                y_vel = 0
            if event.key == pygame.K_DOWN:
                y_vel = 0
            if event.key == pygame.K_SPACE:
                shooting = False
        if event.type == pygame.MOUSEBUTTONUP:
            shooting = False
    if game_state == "game":
        
        
            
            
        
        if player_health>=1:
            exhaust.append(particle(player_x+10, player.y+60, GAMESPEED*2,1))
            exhaust.append(particle(player_x+10, player.y+60, GAMESPEED*2,1))
            exhaust.append(particle(player_x+10, player.y+60, GAMESPEED*2,1))
            exhaust.append(particle(player_x+10, player.y+60, GAMESPEED*2,1))
        for p in exhaust[:]:
                p.render()
                if p.x <= 10:
                    exhaust.remove(p)
        render_text("SCORE: "+str(score),10, 10, (255,255,255), 15)
        render_text("KILLS: "+str(kills),10, 40, (255,255,255), 15)
        if cooldown:
            if cooldown_counter>= 12:
                if player_health >=1:
                    render_text("LIVES: "+healthbar[abs(player_health)],wid-250, 40, (255,255,255), 25)
        if not cooldown:
            if player_health >=1:
                render_text("LIVES: "+healthbar[abs(player_health)],wid-250, 40, (255,255,255), 25)
        if difficulty == "bring em on" or difficulty == "dont hurt me":
            spawnrate =400
        if difficulty == "fry their flesh":
            spawnrate = 30
        score = score + 1
        if not shooting:
            timer = 9
        #temporarily closed shooting method
        # if shooting:
        #     timer+= GAMESPEED/3
        #     if timer>= 10: 
        #         timer = 0
        #         bulletx.append(Bullet(player_x+20, player_y+15, (0,255,0)))
        # for b in bulletx[:]:
        #     b.shoot(GAMESPEED*5, 0)
        #     if b.x >= wid:
        #         bulletx.remove(b)
        spawn_time +=GAMESPEED/3
        if spawn_time>=spawnrate:      
            spawn_time = 0
            # invaders.append(Invador(wid, 2, 200))
            type = random_wave[random.randint(0, len(random_wave)-1)]
            waveSpawning(2, type)
        if cooldown:
            cooldown_timer += GAMESPEED/3
            if cooldown_timer >= 100:
                cooldown_timer = 0
                cooldown = False
            cooldown_counter +=GAMESPEED/3
            if cooldown_counter >=25:cooldown_counter = 0
            if cooldown_counter >= 12:
                player.spwan(player_x, player_y, shooting, player_health)
                
                
        if not cooldown:
            player.spwan(player_x, player_y, shooting, player_health)
        
            
        if cooldown:
            player.acquired_boosters.clear()  
        for b in enemy_bullet[:]:
            b.shoot(-GAMESPEED*5,0)
            if not cooldown: 
                if player.entity.colliderect(b.sprite):
                    enemy_bullet.remove(b)
                    
                    
                    if player_health >= 1:
                        cooldown = True
                    player_health -= 1
        player_y+= y_vel
        if invaders:
            try:
                for i in invaders[:]:
                    i.spawn(0, invaders, i, enemy_bullet  )
                    if i not in invaders:
                        kills +=1         
                    if i.x<=-50:
                        invaders.remove(i)
                    if not cooldown:
                        if i.ent.colliderect(player.entity):
                            player_health -=1
                            cooldown = True 
            except Exception as e:...
        if player_health<= 0:
            player_death_timer +=GAMESPEED/14
            player_x-=GAMESPEED/3
            player.i +=50
            
            if player_death_timer >=30:
                player_death_timer =0
                game_state = "over"
                player_health = 3
    if game_state == "over":
        player_x = 200
        if sc <= score:
            sc+=int(score*(4/100))
        else:
            if ki<=kills:
                ki+=1
        render_text("Game Over!", (wid/2)-200,(hei/2)-50, (255,0,0), 60)
        render_text("Score :"+str(score), (wid/2)-200,(hei/2)+50, (255,0,0), 30)
        render_text(str(kills)+" Killed", (wid/2)-200,(hei/2)+90, (255,0,0), 30)
        invaders.clear()
        enemy_bullet.clear()
        particles.clear()
        exhaust.clear()
        booster.clear()
    if game_state == "home":
        cooldown = True
        render_text("Space Shooter", (wid/2)-200, (hei/2)-100, (255,5,255), 50)
        if blink >= 50:
            render_text("Press Space",(wid/2)-80, (hei/2)-20, (255,255,255), 20)
        pygame.draw.rect(screen, (0, 100, 10), [(wid/2)-150, (hei/2)+50, 270, 120], width = 2)
        render_text("Press Space to shoot",(wid/2)-110, (hei/2)+70, (25,255,255), 15)
        render_text("Press up/down to navigate",(wid/2)-130, (hei/2)+90, (25,255,255), 15)

    pygame.display.update()
    pygame.display.flip()
pygame.quit()
quit()