from turtle import *

speed('fastest')

def costam(dR=10, dK=8, mR=1, mK=8):
    dR *= 10
    mR *= 10
    for i in range(dK):
        fd(dR)
        for i in range(mK):
            fd(mR)
            bk(mR)
            rt(360/mK)
        bk(dR)
        rt(360/dK)

costam(8, 10, 3, 10)

for i in range(5):
    rt(360/10)
    fd(200)
    costam(8, 8, 2, 12)
    bk(200)
    rt(360/10)

exitonclick()
