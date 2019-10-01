from pico2d import *
import math
open_canvas()

grass = load_image('grass.png')
character = load_image('character.png')

x=0
y=0
angle=-90
r=250
while(angle<270):
    clear_canvas_now()
    
    grass.draw_now(400,30)
    character.draw_now(x,y)
    x = 400+r*math.cos(angle/360*2*math.pi)
    y = 325+r*math.sin(angle/360*2*math.pi)
    angle = angle+1
    delay(0.01)

delay(2)
