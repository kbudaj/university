#!/usr/bin/python

def szachownica(n, k):
    fLine = "#" * k + " " * k
    eLine = " " * k + "#" * k
        
    for x in range(2*n):
        if x%2 > 0:
            for a in range(k):
                print fLine * n
        else:
            for a in range(k):
                print eLine * n
                
szachownica(4, 3)    

            
             
