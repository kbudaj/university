slowo = 'zakop'

def sprawdz(slowo1, slowo2):
    mozna = 1
    slowo1 = daj_slownik(slowo1)
    slowo2 = daj_slownik(slowo2)
    print slowo2.keys()
    print slowo1.keys()
    for klucz in slowo2.keys():
        if klucz in slowo1.keys():
            if slowo2[klucz] <= slowo1[klucz]:
                pass
            else:
                return 0
        else:
            return 0
    return mozna

def daj_slownik(slowo):
    litery = {}
    for i in slowo:
        if i in litery:
            litery[i] += 1
        else:
            litery[i] = 1
    
    return litery  
print(sprawdz('zakop', 'pokaz'))
            
