t = int(input())

for _ in range(t):
    n = int(input())
    lst = [] # matrix n*n
    for _ in range(n):
        lst.append(list(map(int, input().split())))
    
    # diagonal upper left to lower right. get min(0, x)
    # (0,n-1) , (n-1, 0). 
    # x + delta
    res = 0
    for delta in range(1-n, n):
        mn = 0
        for x in range(n):
            y = x + delta
            if 0 <= y < n:
                mn = min(mn, lst[x][y])
        res += abs(mn)

    print(res)
