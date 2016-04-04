def czy_pierwsza(k):
    if k<=2:
        return False
    i = 2
    for i in range(2, int(k**0.5)):
        if k%i == 0:
            return False
    return True
			
def gen_numb2(k, n):
    liczba = sum(9 * 10**x for x in range(k))
    while True:
        if '7' * n in str(liczba) and czy_pierwsza(liczba):
            return liczba
        liczba -= 1
        
print gen_numb2(10, 7)
