t = int(input())

def solve():
    x1,y1,x2,y2,x3,y3 = map(int, input().split())

    crossProduct = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)

    if crossProduct < 0:
        print("RIGHT")
    elif crossProduct > 0:
        print("LEFT")
    else:
        print("TOUCH")


for _ in range(t):
    solve()
