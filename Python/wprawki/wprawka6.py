from random import choice

grammar = {'P':['kot', 'pies', 'człowiek', 'żyrafa', 'PSP'], 'S':['i', 'oraz', 'ale nie'],
        'C':['lubią', 'nie cierpią', 'chcą'], 'Z':['grać', 'spać', 'siebie']}

def makeSentence(grammar, sentence):
    sentence = sentence.split(" ")
    tmp_sentence = []
    for word in sentence:
            tmp_sentence.append(list(word))
    sentence = tmp_sentence

    repeat = 0
    for j in range(len(sentence)):
        for i in range(len(sentence[j])):
            k = sentence[j][i]
            if k in grammar.keys():
                sentence[j][i] = choice(grammar[k])

    new_sentence = []

    for word in sentence:
        new_word = []
        for letter in word:
            single = 0
            if len(letter) == 1:
                single = 1
                new_word.append(letter)
            else:
                single = 0
                new_word.append(letter)
        if single == 1:
            new_sentence.append("".join(new_word))
        else:
            for item in new_word:
                new_sentence.append(item)

    return " ".join(new_sentence)
    

def sumuj(L):
    

print(makeSentence(grammar, 'Wszyscy wiedzą, że: PSPCZ'))
