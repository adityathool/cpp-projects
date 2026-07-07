import pygame
import random
pygame.init()
size = 40
wid = 20*size
hei = 9*size
screen = pygame.display.set_mode((wid, hei))
player_sizey = 40
player_x = 100
player_y = hei/2-player_sizey/2
y_vel = 0


class Invador():
    def __init__(self, health):
        self.x = 0
        self.y = 0
        self.health = health
        
    def spawn(self,x,y, collider_list):
        self.x = x
        self.y = y
        self.ent = pygame.draw.rect(screen, (255,100,0), [self.x, self.y, 40,40])
        for obj in collider_list:
            if self.ent.colliderect(obj.bullet):
                collider_list.remove(obj)
                self.health -= 10

        
        

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
    def shoot(self, speedx, speedy):
        self.x += speedx
        self.y += speedy
        # self.bullet = draw_rotated_ellipse(screen, (0,255,0), self.x-10+30, self.y+player_sizey/2, 15,3,-speedy*10)
        # self.x-10+30, self.y+player_sizey/2, 15,3
        self.bullet = pygame.draw.rect(screen, (0,255,0), [self.x-10+30, self.y+player_sizey/2, 15,3])

bullet = Bullet(player_x, player_y)
bulletx = []
bullety = []
bulletj = []

invaders = []


shooting = False
booster1 = False
booster2 = False 
game = True
w= 0
clock = pygame.time.Clock()
timer = 0
deleted_inv = -1

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

    if not shooting:
        t=9
    if shooting:
        
        timer+= 1
        if timer>= 9:
            timer = 0
            
            bulletx.append(Bullet(player_x, player_y))
            if booster1 and not booster2:
                bullety.append(Bullet(player_x, player_y))
                bulletj.append(Bullet(player_x, player_y))
                bulletx.clear()
                print("booster 1 and not 2")
            elif booster2 and booster1:
                bulletx.append(Bullet(player_x, player_y))
                bullety.append(Bullet(player_x, player_y))
                bulletj.append(Bullet(player_x, player_y))
                print("booster 1 and 2")
        
    for b in bulletx[:]:
        b.shoot(15, 0)
        if b.x >= wid:
            bulletx.remove(b)

    for by in bullety[:]:
        by.shoot(15,1)
        if by.x >= wid:
            bullety.remove(by)

    for bj in bulletj[:]:
        bj.shoot(15,-1)
        if bj.x >= wid:
            bulletj.remove(bj)

    for j in range(0,7):
        for i in range(0,2):
            invaders.append(Invador(100))
            invaders[i].spawn((wid-100)-50*i, 10+50*j, bulletx)
            
    

    player = pygame.draw.rect(screen, (0,100,0), [player_x, player_y, 60, player_sizey])
    player_y+= y_vel

    

    pygame.display.update()
    pygame.display.flip()
pygame.quit()
quit()