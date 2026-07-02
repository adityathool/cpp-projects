import pygame
pygame.init()
size = 40
wid = 20*size
hei = 9*size
screen = pygame.display.set_mode((wid, hei))
player_sizey = 40
player_x = 100
player_y = hei/2-player_sizey/2
y_vel = 0

class Bullet():
    def __init__(self, x,y):
        self.x = x
        self.y = y
        
        self.bullet = None
    def shoot(self, speedx, speedy):
        self.x += speedx
        self.y += speedy
        
        
        self.bullet = pygame.draw.ellipse(screen, (0,255,0), [self.x-10+30, self.y+player_sizey/2, 10,10])
        
        
        
class Invador():
    def __init__(self, x,y, health):
        self.x = x
        self.y = y
        self.health = health
        self.ent = None

    def spawn(self, x,y):
        self.x -= 0.01
        self.x = x
        self.y = y
        self.ent = pygame.draw.rect(screen, (255,100,0), [self.x, self.y, 40,40])

    def is_colliding(self,collider):
        return self.ent.colliderect(collider)


bullet = Bullet(player_x, player_y)
bulletx = []
bullety = []
bulletj = []

invaders = []

shooting = False
booster1 = False
booster2 = False 
game = True
clock = pygame.time.Clock()
timer = 0
while game:
    clock.tick(60)
    screen.fill((0,0,0))
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

    
    if shooting:
        
        timer+= 1
        if timer>= 7:
            timer = 0
            
            bulletx.append(Bullet(player_x, player_y))
            if booster1 and not booster2:
                bullety.append(Bullet(player_x, player_y))
                bulletj.append(Bullet(player_x, player_y))
                bulletx.clear()
                print("booster 1 and not 2")
            elif booster2 and booster1:
                bulletx.append(Bullet(player_x, player_y))
                print("booster 1 and 2")





            
    for b in bulletx[:]:
        b.shoot(10, 0)
        if b.x >= wid:
            bulletx.remove(b)
        
        for inv in invaders[:]:
            inv.spawn(inv.x, inv.y)
            if inv.is_colliding(b.bullet):
                invaders.remove(inv)

    for by in bullety[:]:
        by.shoot(10,4)
        if by.x >= wid:
            bullety.remove(by)
    for bj in bulletj[:]:
        bj.shoot(10,-4)
        if bj.x >= wid:
            bulletj.remove(bj)

    for i in range(0,7):
        invaders.append(Invador(wid- 100, 10+50*i, 100))
    
        

    
        
        
        
        

            
    
    

    player = pygame.draw.rect(screen, (0,100,0), [player_x, player_y, 60, player_sizey])
    player_y+= y_vel

    

    
    pygame.display.update()
    pygame.display.flip()
pygame.quit()
quit()