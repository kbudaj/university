def ciagi(N, dziedzina):
    """ Zwraca wszystkie możliwości wartościowań zmiennych na dziedzinie """
    if N == 0:
        return [[]]
    #print([ [d] + reszta for d in dziedzina for reszta in ciagi(N-1, dziedzina)])
    return [ [d] + reszta for d in dziedzina for reszta in ciagi(N-1, dziedzina)]

def wartosciowania(zmienne):
    """ Przypisuje wartościowania do zmiennych """
    C = ciagi(len(zmienne), [True, False])
    data = [dict(zip(zmienne,c)) for c in C]
    
    for i in data:
        for zmienna in i:
            if zmienna == 'True' and i[zmienna] == False:
                i[zmienna] = True
            elif zmienna == 'False' and i[zmienna] == True:
                i[zmienna] = False
    return data

def zmienne(f):
    """ Zwraca zmienne jakie wystepuja w formule """
    zmienne = ''
    for x in f:
        if x.isalpha():
            zmienne += x
        else:
            zmienne += ','
    zmienne = zmienne.split(',')
    zmienne = filter(None, zmienne)
    return list(zmienne)


def wartoscFormuly(f, w):
    """ Zwraca wartość formuły """
    f = f.replace('!',' not ').replace('*',' and ').replace('+',' or ')
    return eval(f, w)

def spelnialna(f):
    """ Sprawdza czy jakakolwiek wartość formuły jest True """
    return any( [wartoscFormuly(f,w) for w in wartosciowania(zmienne(f))])

def tautologia(f):
    """ Sprawdza czy wszystkie wartości formuły są True """
    return all([wartoscFormuly(f,w) for w in wartosciowania(zmienne(f))])

for f in ['pap + True', 'arka * !a', 'a + !a',  'p * q + !(p*q)']:
    #print(f, spelnialna(f))
    print(f, tautologia(f))
