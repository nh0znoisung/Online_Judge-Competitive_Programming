M = int(1e7) + 10

# Time: O(n*log(log(n)))
# Space: O(n)
def sieve_of_eratosthenes(n):
    # Index: 0-n
    primes = [True] * (n+1)
 
    for i in range(2, int(n**0.5)+1):
        if primes[i]:
            for j in range(i**2, n+1, i):
                primes[j] = False
    
    for i in range(3, n-1):
        if primes[i] and not primes[i+2]:
            primes[i] = False
    
    return [i for i in range(2, n+1) if primes[i]]

arr = sieve_of_eratosthenes(M)
size = len(arr)
# print(arr[:10])

# O(log n)
def count_smaller(n):
    left, right = 0, size
    while left < right:
        mid = (left + right) // 2
        if arr[mid] < n:
            left = mid + 1
        else:
            right = mid
    return left

# prefix sum: O(1)

t = int(input())

for i in range(t):
    n = int(input()) # n >= 1 & n <= 1e7, Log2(n) = 24

    # 2 is smallest but 2 = 5-3. If n < 5, result = 0
    # n == 4 | res = 1 (False case)
    if n < 5:
        res = 0
    else:
        # Find <= n-2. At most n, p = p1-p2 <= N-2. Count <= N-2 | Count < N-1
        res = count_smaller(n-1)
    
    print(f"Case #{i+1}: {res}")