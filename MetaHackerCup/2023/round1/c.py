t = int(input())

for i in range(t):
    n = int(input())
    s = [bool(ele) for ele in list(input())]
    q = int(input())
    
    # Change
    for _ in range(q):
        b = int(input())
        for j in range(b,n+1,b):
            s[j-1] ^= 1
    
    # Min
    res = 0
    for j in range(1,n+1):
        if s[j-1]:
            res += 1
            for k in range(j,n+1,j):
                s[k-1] ^= 1
            
    print(f"Case #{i}: {res}")