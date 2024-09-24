n = int(input())

for i in range(n):
    n, k = map(int, input().split(' '))
    mn = 1e9 + 11
    for j in range(n):
        s = int(input())
        mn = min(mn, s)
    
    ss = mn if n == 1 else mn * (2 * n - 3)
    if ss <= k:
        print(f"Case #{i+1}: YES")
    else:
        print(f"Case #{i+1}: NO")

    