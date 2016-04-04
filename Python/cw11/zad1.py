# https://kno.ii.uni.wroc.pl/ii/mod/page/view.php?id=18041

def funkcja(L, n):
    i = 0
    while i < len(L):
        if len(L[i]) < n:
            L[i] = L[i][::-1]
        i += 1
    return L

print(funkcja(['tak', 'witam', 'jan', 'kurkunatolo'], 7))
