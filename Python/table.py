import turtle

n=0

while n<=5:
    turtle.penup()
    turtle.goto(0,100*n-200)
    turtle.pendown()
    turtle.forward(500)
    
    n=n+1
n=0
turtle.right(90)
turtle.penup()
turtle.goto(0,500)
while n<=5:
    turtle.penup()
    turtle.goto(100*n,300)
    turtle.pendown()
    turtle.forward(500)
    
    n=n+1
