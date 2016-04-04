def first(l):
    if len(l) == 0:
        return set([0])
    s = first(l[:-1])
    return s | set([l[-1] + x for x in s])

def second(n, a, b):
    if n == 1:
        return [[i] for i in range(a, b + 1)]
    return [l + [i] for l in second(n - 1, a, b) for i in range(l[-1], b + 1)]

print("A: ", end="")
print(first([1,2,3,100]))

print("B: ", end="")
print(second(3, 1, 3))

