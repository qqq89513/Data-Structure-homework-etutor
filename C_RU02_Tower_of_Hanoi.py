tower_A=[]
tower_B=[]
tower_C=[]

def disp():
  print("A:", end='')
  for A in tower_A: print(" {}".format(A), end='')

  print("\nB:", end='')
  for B in tower_B: print(" {}".format(B), end='')

  print("\nC:", end='')
  for B in tower_C: print(" {}".format(B), end='')

  print("\n******************\n");

def hanoi(n, a, b, c):
  if n == 1:
    print(a, '-->', c)
    if   a=='A':  val=tower_A.pop()
    elif a=='B':  val=tower_B.pop()
    elif a=='C':  val=tower_C.pop()
    else :  raise("Ref error")

    if   c=='A':  tower_A.append(val)
    elif c=='B':  tower_B.append(val)
    elif c=='C':  tower_C.append(val)
    else :  raise("Ref error")

    disp()

  else:
    hanoi(n - 1, a, c, b)
    hanoi(1    , a, b, c)
    hanoi(n - 1, b, a, c)

n=int(input())
tower_A=list(range(n, 0, -1))
disp()
hanoi(n, 'A', 'B', 'C')