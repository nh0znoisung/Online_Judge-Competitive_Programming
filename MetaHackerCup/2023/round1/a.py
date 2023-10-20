t = int(input())

for i in range(t):
    try:
        n = int(input())
        lst = [int(i) for i in input().split(' ')]
        lst.sort()
        # print(lst)

        if n == 5:
            result = max( (lst[-1] + lst[-2]) / 2 - (lst[0] + lst[2]) / 2,
                        (lst[-1] + lst[-3]) / 2 - (lst[0] + lst[1]) / 2)
        else:
            result = ( (lst[-1] + lst[-2] - lst[0] - lst[1]) / 2)
    except:
        result = 0


    text = f"Case #{i+1}: {round(result, 6)}"
    print(text)