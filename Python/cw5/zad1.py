def F(n):
    if n % 2 == 0:
        return n/2
    else:
        return 3*n+1

def energyF(n):
    counter = 0
    while n != 1:
        counter += 1
        n = F(n)

    return(counter)

def average(L):
    a = 0
    for x in L:
        a += x
    return a/len(L)

def analizaCollatza(a, b):
    L = map(energyF, range(a, b))
    L = list(L)

    L.sort()
    if len(L) % 2 == 0:
        mediana = L[len(L)//2]
    else:
        mediana = L[len(L)//2] + L[len(L)//2+1] // 2

    print("Srednia: {}".format(average(L)))
    print("Mediana: {}".format(mediana))
    print("Minimalna: {}".format(min(L)))
    print("Maksymalna: {}".format(max(L)))


analizaCollatza(2, 7)
