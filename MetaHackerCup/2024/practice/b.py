t = int(input())

for i in range(t):
    n, p = map(int, input().split(" "))
    res = ((p/100)**((n-1)/n)) * 100 - p
    print(f"Case #{i+1}: {res:.14f}")