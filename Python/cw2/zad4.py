from duze_cyfry import dajCyfre

def dlc(liczba):
    liczba = str(liczba)
    liczbaTable = []

    for i in range(len(liczba)):
        liczbaTable += [dajCyfre(int(liczba[i]))]

    lineTable = [[] for x in range(5)]
    print lineTable

    for i in range(len(liczbaTable)):
        for j in range(len(liczbaTable[i])):
            lineTable[j] += [liczbaTable[i][j]]

    for i in range(len(lineTable)):
        buff = ""
        for j in range(len(lineTable[i])):
            buff += " " + lineTable[i][j]
        print buff

dlc(1337)
