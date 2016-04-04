# -*- encoding: utf8 -*-

slowo = 'test'

def sprawdz(podane):
    for slowo in dic:
        niemozna = 0
        for klucz in dic[slowo].keys():
            if klucz in dic[podane].keys():
                if dic[slowo][klucz] <= dic[podane][klucz]:
                    pass
                else:
                    niemozna = 1
            else:
                niemozna = 1
        if niemozna == 0:
            print("{} mozna zbudować ze słowa {}".format(slowo, podane))

slowo_1 = {}
for litera in len(slowo):
    try:
        if slowo_1[i]:
            slowo_1[i] += 1
    except:
        slowo_1[i] = 1
print(slowo_1)