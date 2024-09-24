import random
t = int(input())

def gcd(a, b):
        while b:
            a, b = b, a % b
        return a

def do_sample(lst: list):
    # do_sample(lst) -> number of points in the line with random 2 points
    # Time: O(n * gcd) | n >= 2 -> existed a pair
    # Do slove and bias using float is wrong (y = a * x + b | a, b is floating numbers)
        # Using GCD instead (a * x + b * y + c = 0)
    p1, p2 = random.sample(lst, 2) # p (x,y) | Time: O(2) = O(1)
    # y = ax + b
    count = 0
    if p1[0] == p2[0]:
        # Ptdt: x - p1[0] = 0
        # print(f"Line: x - {p1[0]} = 0")
        for point in lst:
            if point[0] == p1[0]:
                count += 1
    elif p1[1] == p2[1]:
        # No cases on 2 conditions: no any 2 points have the same coordinates
        # Ptdt: y - p1[1] = 0
        # print(f"Line: y - {p1[1]} = 0")
        for point in lst:
            if point[1] == p1[1]:
                count += 1
    else:
        # Ptdt: a * x + b * y + c = 0
        # p1[0] != p2[0] and p1[1] and p2[1]
        # a * (x2- x1) + b * (y2-y1) = 0
        # a * (x2- x1) / gcd + b * (y2-y1) /gcd = 0
            # a = -(y2 - y1) / gcd = -dy // g
            # b = (x2 - x1) / gcd = dx // g
        dy = p2[1] - p1[1]
        dx = p2[0] - p1[0]
        g = gcd(dx,dy)

        a = -dy//g
        b = dx//g
        c = - a * p1[0] - b * p1[1]

        # print(f"Line: {a} * x + {b} * y + {c} = 0")
        for point in lst:
            if a * point[0] + b * point[1] + c == 0:
                count += 1
    return count



for i in range(t):
    res = 0 # Final result

    n = int(input()) # n >= 2
    lst = []
    for _ in range(n):
        x, y = map(int, input().split())   
        lst.append((x, y))
    # m: number of ants need to move
    # p = n-m: number of ants on the optimal line

    k = 40 # ? number of trial | Time: O(n*k)
        # 1 trial: have 0.25 that 2 points on the optimal line | 0.75 that 2 points not the optimal line
        # 0.75 ^ k: prob that not found the optimal line | 0.75 ^ 40 = 0.01% (3 testcase fall with n = 35,6,48)
        # Total complexity: 10^6 * 40 | Due to Max(n) = 10^6
        # Brute force: k > n * (n-1) / 2 => n*k = n^3 /2 => n < 430
    p = 0 # Find number of ants on the optimal line

    if n < 400: # Do brute force
        k = (n * (n-1)) // 2 + 10

    for __ in range(k):
        x = do_sample(lst)
        p = max(x, p)
        # print(x, p)

    print(f"Case #{i+1}: {n-p}")
