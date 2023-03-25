import pygame as p

def draw_x(x,y,size):
    p.draw.line(screen,red,[x,y],[x+size,y+size],10)
    p.draw.line(screen,red,[x+size,y],[x,y+size],10)

def check_win(c,player,history):
    for i in range(c):
        state_win=True
        for j in range(c):
            if history[i][j]!=player:
                state_win=False
        if state_win:
            return True

    for i in range(c):
        state_win=True
        for j in range(c):
            if history[j][i]!=player:
                state_win=False
        if state_win:
            return True
    for i in range(c):
        if history[i][i]!=player:
            state_win=False
        if state_win:
            return True
    for i in range(c):
        if history[i][(c-1)-i]!=player:
            state_win=False
        if state_win:
            return True  
p.init()


c=3
size=100

history=[[0]*c for i in range(c)]

width=size*c
height=size*c

screen=p.display.set_mode((width,height))

white=(255,255,255)
black=(0,0,0)
blue=(0,0,255)
red=(255,0,0)

turn=0

screen.fill(white)



for j in range(c):
    for i in range(c):
        p.draw.rect(screen,black,[i*size,j*size,size,size],1)

        

p.display.update()    
run=True

while run:
    
    for event in p.event.get():
        if event.type==p.QUIT:
            run=False
        
        if event.type==p.MOUSEBUTTONDOWN:
            x,y=p.mouse.get_pos()

            for j in range(c):
                for i in range(c):
                    if i*size<x<i*size+size and j*size<y<j*size+size:
                        #p.draw.rect(screen,black,[i,j,size,size])
                        if history[j][i]==0:
                            if turn==0:
                                p.draw.circle(screen,blue,[i*size+size/2,j*size+size/2],size/2,5)
                                turn=1
                                history[j][i]=1
                            else:
                                draw_x(i*size,j*size,size)
                                turn=0
                                history[j][i]=2
                                

                        #         색 , 위치(중점), 반지름, 테두리
    p.display.update()
p.quit()

