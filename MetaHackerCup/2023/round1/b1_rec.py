# Recursion method

# If have divisor > 41 -> Skip for it
def get_divisors(p: int):
    divisors = []
    for i in range(41,1,-1):
        if p % i == 0:
            divisors.append(i)
    
    return divisors

def total(lst:list):
    s = 0
    for i in lst:
        s += i
    return s

def solve(number: int, sum: int):
    global tracking, result
    # print(number, sum, tracking)
    if number == 1 and total(tracking) <= 41:
        print("Hello")
        if (41-total(tracking) + len(tracking) < 41-total(result) + len(result)):
            result = tracking
        return

    
    if sum == 0:
        return
    

    for i in lst:
        if number % i == 0 and sum >= i:
            tracking.append(i)
            solve(number//i, sum-i)
            tracking.pop()


t = int(input())

for i in range(t):
    p = int(input())
    lst = get_divisors(p) # Global variable
    tracking = []
    result = []
    check = False


    solve(p, 41)
    # print(lst)
    # print(result) 
    s = total(result)
    if result == -1:
        ss = '-1'
    else:
        ss = str(len(result) + 41 - s)
        for j in result:
            ss = ss + ' ' + str(j)
        for j in range(41-s):
            ss = ss + ' 1'
        

    text = f"Case #{i+1}: " + ss
    print(text)


