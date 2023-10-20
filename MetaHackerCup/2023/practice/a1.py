n = int(input())

for i in range(n):
    [A,B,C] = [int(i) for i in input().split(' ')]
    result = 2*(C//B) - 1
    if C >= A:
        # x1 max
        x = (C-A)//A
        y = ((C-A)-x*A)//B
        result = max(result, x + 2*y + 1)

        # y max
        y = (C-A)// B
        x = ((C-A)-y*B)//A
        result = max(result, x + 2*y + 1)
    result = max(0, result)

    text = f"Case #{i+1}: {result}"
    print(text)