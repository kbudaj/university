# Zadanie 4 Lista 6
#python2.7

words = {}
for word in open("slowa.txt"):
        words[unicode(word[:-1], encoding = "utf-8")] = 0

def isValid(inWord, outWord):
        for i in range(1, len(outWord)):
                if outWord[:i] + inWord + outWord[i:] in words:
                        return True
        return False

def f(filename):
        srcWords = []
        for word in open(filename):
                srcWords += [unicode(word[:-1], encoding = "utf-8")]

        for i in srcWords:
                for j in srcWords:
                        if isValid(j, i):
                                print(j + ", " + i)

f("slowa_z1.txt")
