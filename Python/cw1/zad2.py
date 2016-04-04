# -*- coding: utf-8 -*-

def silnia(x):
  resoult = 1
  for k in range(1, x):
    resoult *= x
  return resoult 

for k in range(1, 101):
  charAmount = len(str(silnia(k)))
  print '%d! ma %d cyfry' % (k, charAmount)   
