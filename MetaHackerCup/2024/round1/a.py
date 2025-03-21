t = int(input())

for i in range(t):
    n = int(input()) 
    
    max_a, min_b = -11, 1e6 + 11
    for j in range(n):
        a, b = map(int, input().split())
        max_a = max((j+1)/b, max_a)
        if a != 0:
            min_b = min((j+1)/a, min_b)
    
    res = max_a if max_a <= min_b else -1
    print(f"Case #{i+1}: {res:.6f}")