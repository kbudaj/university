def burp(word):
    ltrs = {}
    line = []

    for letter in word:
        if letter not in ltrs:
            ltrs[letter] = len(ltrs) + 1
        line.append(str(ltrs[letter]))
    return "-".join(line)

print(burp('indianin'))
