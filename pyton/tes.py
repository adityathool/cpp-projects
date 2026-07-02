import time
import random

class Pipe():
    def __init__(self,x,y):
        self.x = x
        self.y = y
    def move(self):
        self.x  = 4
pipe = Pipe(2,3)
pipe.move()
run = True
l = [1, 2, 3, 4,5,6,7]
x = 0
if len(l)>=5:
    l.pop(0)


# builing a list that constanlty adds a random number at its end
randlist = []

while(run):
    
    l[0] = x
    l.append(2)
    for i in range(1,len(l)):
        l[i] = 100+l[i-1]

    randlist.append(random.randint(0,25))
    
    
    

    x -= 1
    print(l)
    # print(randlist)
    time.sleep(1)
