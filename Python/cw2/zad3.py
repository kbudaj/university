def kolo(r):
    buff = []
    for i in range(1, 2*r):
        str1 = ""
        for j in range(1, 2*r):
            if (r**2) > ((i-r)**2 + (j-r)**2):
                str1 += "#"
            else:
                str1 += " "
        buff += [str1]

    return buff

def balwan(r1, r2, r3):
    """
    r1 - glowa (najmniejszy promien)
    r2 - tulow (srednio promien)
    r3 - nogi  (najwiekszy promien)
    """
    
    for i in kolo(r1):
        print " " * abs(r1 - r3) + i

    for i in kolo(r2):
        print " " * abs(r2 - r3) + i

    for i in kolo(r3):
        print i


balwan(8, 12, 15)
