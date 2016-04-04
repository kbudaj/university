# -*- coding: utf-8 -*-

def potega(a,n):
   wynik = 1 
   for i in range(n):
      wynik = wynik * a   #
   return wynik
   
def kwadrat(n):
   for i in range(n):
      for j in range(n):  
         print "*",
      print
      
def kwadrat2(n):
   for i in range(n):
      print n * "#"      

print

for i in range(5):
   print "Przebieg:",i
   print 20 * "-"
   kwadrat(3+2*i)
      
for i in range(5):
   print "Przebieg:",i
   kwadrat2(3+i)           
     
   
