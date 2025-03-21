t = int(input())

N = int(3e5 + 11)
lst = [0] * N
n = 0
count = 0

def solve(curr):
    global lst, count

    # print(f"Solve curr: {curr}, lst: {lst[:n]}")

    # Check all is 0
    check = True
    for i in range(n):
        if lst[i] >= 0:
            check = False
            break
    if check:
        count = max(count, curr)
        return
    
    for i in range(1, n):
        if lst[i] == 0:
            for j in range(n):
                lst[j] -= i
            # print(i, "Call solve", curr + i, lst[:n])
            solve(curr + i)
            for j in range(n):
                lst[j] += i

for _ in range(t):
    n = int(input()) 
    count = n # Current length
    l = list(map(int, input().split()))

    for i in range(n):
        lst[i] = l[i] - (n - i)

    solve(n)
    print(count)