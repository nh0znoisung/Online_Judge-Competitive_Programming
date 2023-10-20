import math

def get_divisors(number):
    divisors = []
    for i in range(1, int(math.sqrt(number)) + 1):
        if number % i == 0:
            divisors.append(i)
            if i != number // i:
                divisors.append(number // i)
    divisors.sort()
    return divisors

def get_divisor_dict(number):
    divisor_dict = {}
    divisor_list = get_divisors(number)

    for i in divisor_list:
        if i == number:
            divisor_dict[i] = divisor_list
        elif i == 1:
            divisor_dict[i] = [1]
        else:
            divisor_dict[i] = get_divisors(i)
    
    return divisor_dict

def solve(p: int, sum: int, rem: int):
    global tracking, result, check
    if sum == 0 and p == 1:
        result = tracking
        check = True
        return None
    
    if rem == 0:
        return None

    for i in divisor_dict[p][::-1]:
        if sum >= i:
            tracking.append(i)
            solve(p/i, sum-i, rem - 1)
            if check:
                return None
            tracking.pop()

def run(p: int) -> list:
    global tracking, result, check, divisor_dict
    divisor_dict = get_divisor_dict(p)
    print(divisor_dict)

    tracking = []
    result = []
    check = False

    # solve(p, 41, 100)

    if not check:
        ss = '-1'
    else:
        ss = str(len(tracking))
        # print(tracking)
        for c in tracking:
            ss += ' ' + str(c)
    return ss


t = int(input())

for i in range(t):
    p = int(input())
    ss = run(p)

    text = f"Case #{i+1}: " + ss
    print(text)
