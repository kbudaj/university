# -*- encoding: utf8 -*-
from turtle import *
from random import choice, randint
from math import factorial

BOK = 20
speed('fastest')
colormode(255)

def skok_koloru(dlugosc):
    liczba = 0
    for i in range(1, int(dlugosc)+1):
        liczba += i

    return 255//liczba

def kwadrat(bok, kolor):
    color("black", (0, kolor, 200))
    begin_fill()

    for i in range(4):
        fd(bok)
        rt(90)

    end_fill()

def rysunek(dlugosc):
    skok_k = skok_koloru(dlugosc)
    print(skok_k)

    kolor = 0

    for i in range(1, dlugosc+1):
        for k in range(int(i)):
            kolor += skok_k
            kwadrat(BOK, kolor)
            print("Kolor: {}".format(kolor))
            fd(BOK)
        pu()
        fd(BOK)
        pd()
        rt(90)


rysunek(18)
input()
