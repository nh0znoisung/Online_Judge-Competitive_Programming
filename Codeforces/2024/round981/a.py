# sa (FIRST): neg (-1, -5)
    # -1, -3

# ko (SECOND): pos (3, 7)
    # 2, 4

# abs(i) <= n, who first
# n even => Kosuke
# n odd => Sakurako

t = int(input())

for _ in range(t):
    n = int(input())
    if n % 2 == 0:
        print("Sakurako")
    else:
        print("Kosuke")