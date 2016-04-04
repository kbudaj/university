# -*- coding: utf-8 -*-

from losowanie_fragmentow import losujFragment

def losujHaslo(n):
  haslo = ""
  
  while len(haslo) < n:
    tmpHaslo = haslo + losujFragment()
    if len(tmpHaslo) <= n:
      if (n-len(tmpHaslo)) != 1:
        haslo = tmpHaslo 
 
  return haslo

for x in range(10):
  print losujHaslo(8)

for x in range(10):
  print losujHaslo(10)

for x in range(12):
  print losujHaslo(12)
