from turtle import *

BOK = 200 # dostosowac zaleznie od rozdzielczosci
speed('fastest')

def rysunek():
    bok = BOK
    for x in range(8):
        for x in range(4):
            fd(bok)
            rt(90)
        pu()
        fd((bok-(bok-20))/2)
        rt(90)
        fd((bok-(bok-20))/2)
        lt(90)
        pd()
        bok -= 20

rysunek()
exitonclick()
