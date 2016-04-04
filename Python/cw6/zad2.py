# -*- encoding: utf8 -*-

slowa = open('slowa.txt', 'r').read().split('\n')
dic = {}

for slowo in slowa:
    dic[slowo] = 0

for slowo in dic:
    if slowo[::-1] in dic:
        if dic[slowo] == 0 and dic[slowo[::-1]] == 0:
            print(slowo)
            dic[slowo] = 1
            dic[slowo[::-1]] = 1
