import random

dictionary = {}
wordsF = {}

for line in open("pol_ang.txt", encoding = "utf-8"):
    line = line[:-1]
    if " " in line:
        continue
    L = line.split("=")
    if len(L) != 2:
        continue
    pl, en = L

    if not pl in dictionary:
        dictionary[pl] = []
    dictionary[pl].append(en)

for line in open("brown.txt", encoding = "utf-8"):
    for word in line.lower().split():
        if word in wordsF:
            wordsF[word] += 1
            continue
        wordsF[word] = 1

def translateWord(wordPl):
    if wordPl in dictionary:
        bestW = dictionary[wordPl][0]
        bestF = 0
        if bestW in wordsF:
                bestF = wordsF[bestW]

        for wordEn in dictionary[wordPl]:
            if wordEn in wordsF:
                if wordsF[wordEn] > bestF:
                    bestW = wordEn
                    bestF = wordsF[wordEn]
                elif wordsF[wordEn] == bestF:
                    bestW = random.choice([bestW, wordEn])

        return bestW
    else:
        return "?"

def translate(phrase):
    for word in phrase.lower().split():
        print(translateWord(word) + " ", end = "")

translate('koń')
