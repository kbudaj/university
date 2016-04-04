from math import sqrt

def czyPierwsza(n):
    if n <= 2:
        return False
    k = 2
    while k < sqrt(n):
        if n%k == 0:
            return False
        k += 1
    return True

for x in range(1, 100000):
    if '777' in str(x):
        if czyPierwsza(x):
            print(x)
