MOD = 10**9 + 7

def pisano_period(k):
    previous, current = 0, 1
    period = [0, 1]
    for i in range(2, k * k + 1):
        previous, current = current, (previous + current) % k
        period.append(current)
        # Pisano period repeats after "0, 1"
        if previous == 0 and current == 1:
            return period[:-2]
    return period

def find_divisible_indices(period, k):
    divisible_indices = []
    for idx, fib in enumerate(period):
        if fib % k == 0:
            divisible_indices.append(idx + 1)  # Indexing starts from 1
    return divisible_indices


max_k = 10**5
pisano_cache = {}
divisible_indices_cache = {}

def precompute():
    for k in range(1, max_k + 1):
        period = pisano_period(k)
        pisano_cache[k] = period
        divisible_indices_cache[k] = find_divisible_indices(period, k)


def find_nth_divisible_index(divisible_indices, n):
    if n > len(divisible_indices):
        return -1  # No valid answer
    return divisible_indices[n - 1]  # 1-based index


def solve(test_cases):
    precompute()
    results = []
    for n, k in test_cases:
        period = pisano_cache[k]
        divisible_indices = divisible_indices_cache[k]
        period_len = len(divisible_indices)

        result = find_nth_divisible_index(divisible_indices, n)
        if result == -1:
            results.append(-1)
        else:
            results.append(result % MOD)
    
    return results


t = int(input())
test_cases = [tuple(map(int, input().split())) for _ in range(t)]

results = solve(test_cases)
for result in results:
    print(result)
