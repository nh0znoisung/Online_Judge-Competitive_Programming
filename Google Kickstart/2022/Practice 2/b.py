n = int(input())

for i in range(1,n+1):
    s = input().split()

    a, b = int(s[0]), int(s[1])

    print("Case #{}: {}".format(i, int(min(a,b) * (min(a,b) + 1)/2)))
