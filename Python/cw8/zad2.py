from random import shuffle

def mieszaj(L):
    R = []
    for slowo in L:
        if len(slowo) > 4:
            p = slowo[0]
            k = slowo[len(slowo)-1]
            mid = slowo[1:-1]
            mid = list(mid)
            shuffle(mid)
            entry = p + "".join(mid) + k
            R.append(entry)
         else:
            R.append(slowo)
        
    return R
    
print(mieszaj(['Testowy', 'Teskt', 'Program', 'Python', 'tak']))

