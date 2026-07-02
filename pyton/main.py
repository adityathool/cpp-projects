import pygame
import random
import os

pygame.init()

#  1. Get the precise directory of this active script file
SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))

# 2. Combine it into a verified absolute path string
bgpath = os.path.join(SCRIPT_DIR, "bg.png")
basepath = os.path.join(SCRIPT_DIR, "base.png")
b1path = os.path.join(SCRIPT_DIR, "b1.png")
b2path = os.path.join(SCRIPT_DIR, "b2.png")
b3path = os.path.join(SCRIPT_DIR, "b3.png")
tap = os.path.join(SCRIPT_DIR, "begin.png")
title = os.path.join(SCRIPT_DIR, "title.png")
getready = os.path.join(SCRIPT_DIR, "getready.png")


# 3. Print it to your terminal to visually verify where Python is looking
print("LOOKING FOR IMAGE AT:", bgpath)

size = 35
wid =9*size
hei = 16*size

screen = pygame.display.set_mode((wid, hei))
#colors
blue = (0, 150, 255)
brown = (255, 100, 0)
dbrown =(255, 70,0)
green = (150, 255,0)
yellow = (255, 200, 0)
#player coordinates
birdx = 70
birdy = 100
velocity = -3
gravity = 0.2

clock = pygame.time.Clock()
game = True

bg = pygame.image.load(bgpath)
bg = pygame.transform.scale(bg, (wid, hei))

gnd = pygame.image.load(basepath)
gnd = pygame.transform.scale(gnd, (wid, 130))

b1 = pygame.image.load(b1path)
b1 = pygame.transform.scale(b1, (30, 20))

b2 = pygame.image.load(b2path)
b2 = pygame.transform.scale(b2, (30, 20))

b3 = pygame.image.load(b3path)
b3 = pygame.transform.scale(b3, (30, 20))

title = pygame.image.load(title)
title = pygame.transform.scale(title, (200, 60))

tap = pygame.image.load(tap)
tap = pygame.transform.scale(tap, (150, 120))

getready = pygame.image.load(getready)
getready = pygame.transform.scale(getready, (170,60))


class Pipe():
    def __init__(self,x,y,space):
        self.x = x
        self.y = y+random.randint(-50,50)*2
        self.space = space
        self.pipe1 = None
        self.top1 = None
        self.pipe2 = None
        self.top2 = None
        self.sensor = None
    
    def update(self, speed):
        self.x -= speed
        
        self.pipe1 = pygame.draw.rect(screen,green,[self.x, self.y+self.space,40,300 ])
        ref1 = pygame.draw.rect(screen,(255,255,255),[self.x+7, self.y+self.space,6,280 ])
        pygame.draw.rect(screen, (100, 200, 0), [self.x+34, self.y+self.space,6,280 ])
        self.top1 = pygame.draw.rect(screen,green,[self.x-5, self.y+self.space,50,30 ])
        pygame.draw.rect(screen, (100, 200, 0), [self.x-5, self.y+self.space+24,50,6 ])
        pygame.draw.rect(screen, (100, 200, 0), [self.x-5+44, self.y+self.space,6,24 ])
        pygame.draw.rect(screen, (255,255,255), [self.x-5+6, self.y+self.space,6,24 ])
        pygame.draw.rect(screen,(100, 200, 0),[self.x-5, self.y+self.space,50,2 ])
        
        self.sensor = pygame.Rect(self.x+40, self.y-self.space, 1, 2*self.space)
        # pygame.draw.rect(screen, brown,[self.x+40, self.y-self.space, 1, 2*self.space])

        self.pipe2 = pygame.draw.rect(screen,green,[self.x, self.y-250-self.space,40,300 ])
        ref2 = pygame.draw.rect(screen,(255,255,255),[self.x+7, self.y-250-self.space,6,280 ])
        pygame.draw.rect(screen,(100,200,0),[self.x+34, self.y-250-self.space,6,280 ])
        self.top2 = pygame.draw.rect(screen,green,[self.x-5, self.y-250-self.space+280,50,30 ])
        pygame.draw.rect(screen,(100,200,0),[self.x-5+44, self.y-250-self.space+280,6,30])
        pygame.draw.rect(screen,(255,255,255),[self.x-5+7, self.y-250-self.space+280,6,30])
        pygame.draw.rect(screen,(100,200,0),[self.x-5, self.y-250-self.space+280,50,6 ])
        pygame.draw.rect(screen,(100,200,0),[self.x-5, self.y-250-self.space+280+30,50,2 ])
    
    def passed(self, collider, x):
        if not self.sensor:
            return False
        return self.sensor.colliderect(collider) and self.x+40 <= x+1
    
        
    def is_colliding(self,collider):
        if not self.pipe1:
            return False
        return (self.pipe1.colliderect(collider) or
                self.pipe2.colliderect(collider) or 
                self.top1.colliderect(collider) or
                self.top2.colliderect(collider))
class Base():
    def __init__(self,x,y):
        self.x = x
        self.y = y
        self.base = None
        
        
    def render(self,speed):

        self.speed = speed
        self.x -=speed
        self.base = screen.blit(gnd,(self.x,self.y))
        self.base = screen.blit(gnd,(self.x+wid,self.y))
        self.basecollider = pygame.Rect(self.x, self.y, wid, hei-130)
        # pygame.draw.rect(screen, brown, [0, self.y, wid, hei-130])
        

        if self.x <= -wid:
            self.x = 0


    

    def is_colliding(self, collider):
        
        return self.basecollider.colliderect(collider)

def render_text(string, x,y, col, size):
    pygame.font.init()
    font = pygame.font.SysFont("snapitc", size, )
    text = font.render(string, True, col)
    screen.blit(text, [x,y])
    

fly = [b1,b2,b3]
i = 0
anim_speed = 0.1
    
def freeze_game():
    take_input = False
    speed = 0
    velocity = 0
    

x1 = 0
speed = 3

timer = 0
flap_timer = 0
pipes = []
score = 0


gameover= False
start = False


# pipe = Pipe(wid, 200, 80)
base = Base(0, hei-130)
while game:
    clock.tick(60)
    gamerestart = False

    i+=anim_speed
    if i>= len(fly):
        i =0
    image =fly[int(i)]
    
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            game = False
        
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RETURN:
                if gameover:
                    gamerestart = True
            if event.key == pygame.K_ESCAPE:
                if gameover:
                    start = False
                    gamerestart=True
                
                    
                
        
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                start = True
                if birdy >= 0:
                    velocity = -5
    
    bg_speed = speed/2
    screen.blit(bg, (x1, -50))
    screen.blit(bg, (x1+wid, -50))
    if x1 <= -wid:
        x1 = 0
    
    
    if gameover:
        velocity = 0
        speed = 0
        anim_speed = 0
    if not gameover:
        velocity += gravity
        speed = 3
        anim_speed = 0.1
        
    
    if gamerestart:
        gameover = False
        pipes.clear()
        birdy = 100
        score = 0

    
    
    if not start:
        gamerestart = True
        screen.blit(title, (wid/2-100, 20))
        screen.blit(tap, (wid/2-75, 150))
        screen.blit(getready, (wid/2-90, 300))
    

    flap_timer += speed
    if flap_timer>= 152:
        flap_timer=0
        if not start:
            velocity = -5
    

    # for i in range(25):
    #     pipe.spawn(i*200+x, 200+l[i], 80, bird, speed)
    
    bird = screen.blit(image, (birdx, birdy))

    
    
   
    
    
    if timer>= 180:
        timer = 0
        if start:
            pipes.append(Pipe(wid, 200, 90))
        
    for p in pipes[:]:
        p.update(speed)
        if p.is_colliding(bird):
            gameover = True
            
        if p.x< -50:
            pipes.remove(p)
        
        if p.passed(bird, birdx):
            if not gameover:
                score += 1
            
    if start:
        render_text(str(int(score)), wid/2-10,20, yellow, 70)
    
    if gameover:
        render_text("GAME OVER", 14, hei/2-70, (255,0,0), 40)
        render_text("Press Enter To Restart",25, hei/2-30, yellow, 20)
        # render_text("Press Escape To Quit",25, hei/2-15, yellow, 16)

    
    # print(pygame.font.get_fonts())
        


    
    base.render(speed)
    

    

    if base.is_colliding(bird):
        gameover = True
        birdy = hei-130-20


    x1 -= bg_speed
    timer += speed
    

    
    birdy += velocity
    

    pygame.display.update()


pygame.quit()
quit()