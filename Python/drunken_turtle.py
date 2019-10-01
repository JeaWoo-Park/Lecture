import turtle
import random

turtle.shape('turtle')
while(True):
    turtle.setheading(random.randint(0,360))
    turtle.forward(random.randint(50,150))
    turtle.stamp()
