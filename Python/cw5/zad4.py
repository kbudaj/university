# -*- encoding: utf8 -*-
from turtle import *
from random import choice, randint

speed('fastest')
ht()
color('black', 'yellow')
colormode(255)

def poczatkowyWaz(N):
  wynik = []
  for i in range(N):
    wynik.append( (i,0) )
  return wynik

def nast(dx,dy):
   if randint(0,5) != 0:
      return dx,dy
   if dx == 0:
      return choice([-1,1]),0
   return 0, choice([-1,1])

def kwadrat(x,y,bok, c1,c2):
   color(c1,c2)
   pu()
   goto(x * bok, y * bok)
   pd()

   begin_fill()
   for i in range(4):
     fd(bok)
     rt(90)
   end_fill()


tracer(1,0) # nie wchodząc w szczegóły -- przyśpiesza działanie funkcji rysujących modułu turtle

snake = poczatkowyWaz(20)

kolory = [(255, 120, 0)] # głowa
pkolor = randint(80, 200)
kolory.extend([(pkolor, 0+x, 255) for x in range(0, 255, 7)]) # reszta ciala

c = 0
for x,y in snake:
   kwadrat(x,y,10, (0, 0, 0), kolory[c])
   c += 1


dx = 1
dy = 0

while True:
  dx,dy = nast(dx,dy)

  if x > 15 and dx == 1:
      dx = 0
      dy = choice([-1, 1])
  if x < -15 and dx == -1:
      dx = 0
      dy = choice([-1, 1])
  if y > 15 and dy == 1:
      dy = 0
      dx = choice([-1, 1])
  if y < -15 and dy == -1:
      dy = 0
      dx = choice([-1, 1])


  x,y = snake[-1]
  x = x+dx
  y = y+dy



  snake.append( (x,y) )

  # Losowe 'wydluzanie',
  # tutaj akurat w dróga strone bo losuje usuniecie
  # ale dzialanie jest wg sepcyfikacji
  if randint(1, 20) != 1:
    x0,y0 = snake[0]
    del snake[0]
    kwadrat(x0,y0,10, 'white', 'white')
  else:
    print("Dodano nowy element weza!")
    print("Dlugosc: {}".format(len(snake)))

  # Rysowanie weza
  c = 0
  for x, y in reversed(snake):
    kwadrat(x, y, 10, (0, 0, 0), kolory[c])
    c += 1

  # Debug granice
  #
  # dx,dy = nast(dx,dy)
  # snake.append( (x,y) )
  # x0,y0 = snake[0]
  # del snake[0]
  # kwadrat(x0,y0,10, 'white', 'white')
  #
  # kwadrat(x,y,10, 'black', 'yellow')


update() # niepotrzebne, chyba ze w wyniku jakiejs modyfikacji program dojdzie do tego miejsca. W wyniku tego polenia zostają natysowane wszystkie ,,zaległe'' rzeczy, czyli takie, które już zostały wprowadzone, a jeszcze nie znalazły się na ekranie. Chcąc wiedzieć więcej, przeanalizuj działanie funkcji tracer
input()
