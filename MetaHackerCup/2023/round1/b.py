import math
t = int(input())

def solve(p: int) -> str:
    if p == 1:
        ss = '41'
        for i in range(41):
            ss = ss + ' 1' 
        return ss # len = 41, with one ele = 1
    
    count = 0
    lst = []
    for i in range(2, int(math.sqrt(p)) + 1):
        while p % i == 0:
            count += i
            p //= i
            lst.append(i)
    if p > 1:
        lst.append(p)
        count += p
    # print(lst)
    # print(count)
    if count <= 41:
        #TODO
        ss = str(len(lst) + 41 - count)
        for ele in lst:
            ss = ss + ' ' + str(ele)
        for _ in range(41 - count):
            ss = ss + ' ' + '1'
        return ss
    else:
        return '-1'





for i in range(t):
    p = int(input())
    
    ss = solve(p)

    text = f"Case #{i+1}: " + ss
    print(text)