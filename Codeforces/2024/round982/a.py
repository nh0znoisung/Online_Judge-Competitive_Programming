t = int(input())

for _ in range(t):
    n = int(input())
    mxa, mxb = 0, 0
    for _ in range(n):
        a, b = map(int, input().split())
        mxa = max(mxa, a)
        mxb = max(mxb, b)
    
    print((mxa + mxb)*2)