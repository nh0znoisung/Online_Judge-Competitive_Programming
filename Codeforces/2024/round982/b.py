t = int(input())

for _ in range(t):
    n = int(input())
    lst = list(map(int, input().split()))
    right = [] # Count Larger value on the right
    
    # find num of larger elements on the right
    for i in range(n):
        count = 0
        for j in range(i+1, n):
            if lst[j] > lst[i]:
                count += 1
        right.append(count)

    res = 1e10 + 11
    curr = 0
    for i in range(n):
        if lst[i] > curr:
            res = min(res, i + right[i])
    
    print(res)
    