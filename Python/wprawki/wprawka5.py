# https://kno.ii.uni.wroc.pl/ii/pluginfile.php/29016/mod_resource/content/1/wprawka2.pdf

kursy = {"USD": 3.87, "GBP": 5.96, "CZK": 0.157, "EUR": 4.25}
lista = [("USD", 0.75), ("GBP", 150), ("USD", 12), ("USD", 8),
    ("GBP", 380), ("CZK", 1600), ("USD", 4.07), ("EUR", 100)]

def przelicz(L, kurs):
    K = []
    for i in L:
        value = kursy[i[0]] * i[1]
        K.append(value)
    return K

def suma(L):
    return sum(przelicz(L, kursy))

print(suma(lista))
