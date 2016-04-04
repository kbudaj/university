from turtle import *
from random import choice, randint
from duze_cyfry import dajCyfre

BOK = 10

ht()
colormode(255)

def kwadrat(x,y,bok, c1,c2):
   color(c1,c2)
   pu()
   goto(x * bok-100, y * bok-100)
   pd()

   begin_fill()
   for i in range(4):
     fd(bok)
     rt(90)
   end_fill()

def losujKolor():
   #return (randint(0,255), randint(0,255), randint(0,255))
   return choice(['pink', 'orange', 'red', 'green', 'cyan', 'yellow', 'red', 'magenta'])

tracer(5,0)

T = []

for i in range(35):
   T.append(['white'] * 35)

for i in range(500):
  c = randint(0,9)
  dc = dajCyfre(c)[::-1]
  x = randint(0,30)
  y = randint(0,30)
  k = losujKolor()

  konflikt = False

  for dy,wiersz in enumerate(dc):
    for dx,znak in enumerate(wiersz):
      if znak == '#' and T[y+dy][x+dx] != 'white':
        konflikt = True

    for dy,wiersz in enumerate(dc):
        for dx,znak in enumerate(wiersz):
            for obok_y in [-1, 1]:
                for obok_x in [-1, 1]:
                    try:
                        if znak == '#' and T[y+dy+obok_x][x+dx+obok_y] == k:
                            konflikt = True
                    except:
                        pass


  if not konflikt:
    for dy,wiersz in enumerate(dc):
      for dx,znak in enumerate(wiersz):
        if znak == '#':
          kwadrat(x+dx,y+dy, BOK, 'black', k)
          T[y+dy][x+dx] = k

update()
input()
