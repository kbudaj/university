import turtle as t

t.speed('fastest')

def tree(length=100):
    if length < 10:
           return
    t.fd(length)
    t.left(17)
    tree(length * 0.7)
    t.right(34)
    tree(length * 0.7)
    t.left(17)
    t.fd(-length)
    return

tree()
a = input()
