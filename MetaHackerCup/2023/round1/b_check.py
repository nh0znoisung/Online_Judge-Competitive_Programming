def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def first_n_primes(n):
    primes = []
    num = 2
    while len(primes) < n:
        if is_prime(num):
            primes.append(num)
        num += 1
    return primes

n = 59
prime_numbers = first_n_primes(n)

product = 1
for prime in prime_numbers:
    product *= prime

print(f"The product of the first {n} prime numbers is {product}")
# 87714969705038411076272137418539099801877190558970371113762453702525982911939243939521562715111692818014473106390
# Too much for 100 numbers

# 100 number: if 41 number if
print(2**20)
# 576460752303423488


def partition_number(n):
    partition = [0] * (n + 1)
    partition[0] = 1

    for i in range(1, n + 1):
        j = 1
        k = 1
        while j > 0:
            j = i - (3 * k * k + k) // 2
            if j >= 0:
                partition[i] += partition[j] * ((-1) ** (k - 1))
            j = i - (3 * k * k - k) // 2
            if j >= 0:
                partition[i] += partition[j] * ((-1) ** (k - 1))
            k += 1

    return partition[n]

n = 45
result = partition_number(n)
print(f"The partition number of {n} is {result}")