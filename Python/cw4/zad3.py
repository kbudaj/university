# Wymaga python3 (roznica w przedstawianiu range())
from random import randint
from time import time

def randperm(n):
    L = [x for x in range(n)]
    for i in range(len(L)):
        k = randint(0, n-1)
        L[i], L[k] = L[k], L[i]
    return L


print("Przyklad dla randperm(10)")
print(randperm(10))
print("Uruchamiam randperm(10**6)")
start_time = time()
randperm(10**6)
print("Wykonano w: {:f} sekund".format(time() - start_time))
