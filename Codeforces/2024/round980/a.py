n = int(input())

for _ in range(n):
    a,b = map(int, input().split())
    # x => non-profit
    # b-2*x => profit. Max(b-2*x) = result. x = min
    # a >= x + (b-2*x) => x >= b-a. Min x = b-a
    # b > 2*x, b > 2*b - 2*a => 2*a > b
    
    if a >= b:
        print(a) # All-in on profit
    elif 2*a > b: # b > a
        x = b - a
        print(b - 2*x) # Valid > 0
    else:
        print(0) # No solution