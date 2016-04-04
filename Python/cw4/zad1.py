from turtle import *
from random import randint

# Config ########
LEN = 20
colormode(255)
speed("fastest")
#################

def gen_color():
    r = randint(1, 255)
    g = randint(1, 255)
    b = randint(1, 255)
    return r, g, b

def draw_block():
    begin_fill()
    for x in range(4):
        fd(LEN)
        rt(90)
    end_fill()
    penup()
    fd(LEN)
    pendown()

def next_line(y):
    penup()
    rt(90)
    fd(LEN)
    rt(90)
    fd(LEN * y)
    rt(180)
    pendown()

def image_factory(x, y):
    for i in range(y):
        for j in range(x):
            fillcolor(gen_color())
            draw_block()
        next_line(x)


image_factory(10, 10)
exitonclick()
