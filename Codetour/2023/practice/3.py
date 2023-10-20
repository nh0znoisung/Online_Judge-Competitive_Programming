[n,k,c] = [int(x) for x in input().split()]


# n = n1 + n2
# n1 - add
# n2 get -> final result
# in box: 1 + 0.c + (1+c) = n1+n1 + c * n1 * (n1-1)/2  = k + n
# n1 * ( c*n1 - (c-4) )  = 2(k+n)


import math

num = 2*(k+n)
for i in range(1, int(math.sqrt(num)) + 1):
    if num % i == 0:
        if i * (i*c - c + 4) == num:
            print(n - i)
            break

