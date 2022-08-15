n = int(input())

for i in range(1, n+1):
    a, s = int(input()), input()
    c1, c2, c3, c4, c5 = False, False, False, False, False
    if(len(s) >= 7):
        c1 = True
    for char in s:
        if char >= 'a' and char <= 'z':
            c2 = True
        elif char >= 'A' and char <= 'Z':
            c3 = True
        elif char in ['#', '@', '*', '&']:
            c4 = True
        else: #digit
            c5 = True
    
    if not c2: 
        s += 'a'
    if not c3:
        s += 'A'
    if not c4: 
        s += '#'
    if not c5:
        s += '1'
    if not c1:
        rem = 7-len(s)
        s += '1'*rem

    print("Case #{}: {}".format(i, s))