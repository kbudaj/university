program = []
etykiety = {}
linia = 0

for x in open('program.pygo'):
  L = x.split()
  
  
  if len(L) == []:
     program.append( () )
  elif len(L) >= 2 and L[1] == '=':
     program.append( ('=', L[0], ' '.join(L[2:])) )
  elif L[0] == 'if':
     program.append( ('if', ' '.join(L[1:-2]), L[-1] ) )
  elif L[0] == 'goto':
     program.append( ('goto', L[1] ) )
  elif L[0] == 'print':
     program.append( ('print', ' '.join(L[1:])) )
  elif L[0][-1] == ':':
     program.append( () )
     etykiety[L[0][:-1]] = linia
     
 
  else:
     program.append( () )
     
  linia += 1
  
  
pc = 0
dane = {}

while pc < len(program):
  instr = program[pc]
  if instr == ():
    pc += 1
  elif instr[0] == '=':
    zmienna, wyr = instr[1:]
  
    dane[zmienna] = eval(wyr, dane)
    pc += 1
  elif instr[0] == 'if':
    warunek, nowePC = instr[1:]

    if eval(warunek, dane):
      pc = etykiety[nowePC]
    else:
      pc += 1
  elif instr[0] == 'goto':
      
  
      if instr[1] in etykiety:
        pc = etykiety[instr[1]]
        print(pc)
        
        
  elif instr[0] == 'print':
      print eval(instr[1],dane)
      pc += 1
  else:
     print 'Nieznana instrukcja', instr
     pc += 1    
                
