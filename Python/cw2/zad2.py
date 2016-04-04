def koperta(n):  
    n = n*2 + 1
    p = [[0 for x in range(n-2)] for x in range(n-2)]

    
    print "*" * n
    for i in range(len(p)):
        for j in range(len(p[i])):
            p[i][i] = 1
            p[i][-i-1] = 1

    for i in p:
        buff = "*"
        for j in i:
            if j == 1:
                buff += "*"
            else:
                buff += " "
        print buff + "*"

    print "*" * n
    
koperta(10)
