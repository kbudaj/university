char_names = ['Stanisław Wokulski','Izabela Łęcka','Tomasz Łęcki',
                'Panna Florentyna',"Ignacy Rzecki",'Julian Ochocki']
char_count = [0 for x in range(len(char_names))]

for line in open('lalka.txt', 'r'):
    line = line.lower()
    if ('wokulski' in line) or ('stanisław' in line):
        char_count[0] += 1
    if 'izabel' in line:
        char_count[1] += 1
    if 'tomasz' in line:
        char_count[2] += 1
    if 'florentyn' in line:
        char_count[3] += 1
    if ('ignac' in line) or ('rzecki' in line):
        char_count[4] += 1
    if 'ochocki' in line:
        char_count[5] += 1

resoult = sorted(list(zip(char_count, char_names)), reverse=True)

for entry in resoult:
    print("{} : {}".format(entry[1], entry[0]))
