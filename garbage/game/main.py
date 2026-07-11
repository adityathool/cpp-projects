import pygame
import random
import os
pygame.init()
size = 35
wid = 20*size
hei = 9*size
screen = pygame.display.set_mode((wid, hei))
player_sizey = 40
player_x = 100
player_y = hei/2-player_sizey/2
y_vel = 0
SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))
bgpath = os.path.join(SCRIPT_DIR, "ship.png")

ship = pygame.image.load(bgpath)
ship = pygame.transform.scale(ship, (60,50))

class Star():
    def __init__(self,x,y):
        self.x = x
        self.y=y
    def show(self, speed):
        pygame.draw.rect(screen, (255,255,255), [self.x, self.y, 2,2])
        self.x -= speed
        
class Invador():
    def __init__(self,x,y, health):
        self.x = x
        self.xspeed = random.randint(5,7)
        self.y = random.randint(0, hei-40)
        self.health = health
        
    def spawn(self,collider_list,y, memberlist, memberobj):
        self.x -= self.xspeed
        self.y += y
        pygame.draw.rect(screen, (200,50,50), [self.x, self.y, 30,20], width=10, border_radius=3)
        self.ent = pygame.draw.rect(screen, (255,255,255), [self.x, self.y, 30,20], width=2, border_radius=3)

        for obj in collider_list:
            if self.ent.colliderect(obj.bullet):
                collider_list.remove(obj)
                self.health -= 60
                if self.health <= 0:
                    try:
                        memberlist.remove(memberobj)
                    except Exception  as e:
                        ...
def draw_rotated_ellipse(surface, color, x, y, width, height, angle):
    ellipse_surf = pygame.Surface((width, height), pygame.SRCALPHA)
    pygame.draw.ellipse(ellipse_surf, color, (0, 0, width, height))
    rotated_surf = pygame.transform.rotozoom(ellipse_surf, angle,1)
    rotated_rect = rotated_surf.get_rect(center=(x, y))
    surface.blit(rotated_surf, rotated_rect.topleft)

class Bullet():
    def __init__(self, x,y):
        self.x = x
        self.y = y
        self.bullet = None
    def shoot(self, speedx, speedy, y):
        self.x += speedx
        self.y += speedy
    
        # self.bullet = draw_rotated_ellipse(screen, (0,255,0), self.x-10+30, self.y+player_sizey/2, 15,3,-speedy*10)
        # self.x-10+30, self.y+player_sizey/2, 15,3
        self.bullet = pygame.draw.rect(screen, (0,255,0), [self.x-10+30, self.y+y+player_sizey/2, 15,3])
        

bullet = Bullet(player_x, player_y)
bulletx = []


invaders = []
boosters = []
stars = []

shooting = False

game = True
w= 0
clock = pygame.time.Clock()
timer = 0
spawn_time = 0
startime = 0

while game:
    clock.tick(60)
    screen.fill((20,20,20))
    for i in range(0, 200):
        stars.append(Star(i*5, random.randint(0,hei)))
        if len(stars) >= 200:
            stars.pop()

    stars.append(Star(wid, random.randint(0,hei)))
    for s in stars[:]:
        s.show(3)
        if s.x <= 0:
            stars.remove(s)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            game = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                y_vel = -5
            if event.key == pygame.K_SPACE:
                shooting = True
            if event.key == pygame.K_DOWN:
                y_vel = 5
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_UP:
                y_vel = 0
            if event.key == pygame.K_DOWN:
                y_vel = 0
            if event.key == pygame.K_SPACE:
                shooting = False

    if not shooting:
        timer = 9
    if shooting:
        
        timer+= 1
        if timer>= 10:
            timer = 0
            bulletx.append(Bullet(player_x, player_y))
            
    for b in bulletx[:]:
        b.shoot(15, 0, 0)
        if b.x >= wid:
            bulletx.remove(b)

    spawn_time +=1     
    if spawn_time>=30:
        spawn_time = 0
        invaders.append(Invador(wid, 2, 200))

    player = screen.blit(ship, (player_x, player_y))
    # pygame.draw.rect(screen, (0,100,0), [player_x, player_y, 60, player_sizey])
    player_y+= y_vel
    for i in invaders[:]:
        i.spawn(bulletx,0, invaders, i)

        if i.x<=-50:
            invaders.remove(i)
        if player.colliderect(i.ent):
            try: invaders.remove(i)
            except Exception as e: ...
    for boo in boosters[:]:
        boo.spawn()
        if player.colliderect(boo.booster):
            booster1 = True  
            boosters.remove(boo)

    pygame.display.update()
    pygame.display.flip()
pygame.quit()
quit()