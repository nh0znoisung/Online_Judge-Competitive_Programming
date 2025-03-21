def solve(nums):
    prefix_sum = 0
    prefix_sum_map = {0: -1}
    last_end = -1
    count = 0

    for i, num in enumerate(nums):
        prefix_sum += num

        if prefix_sum in prefix_sum_map:
            start = prefix_sum_map[prefix_sum]

            if start >= last_end:
                count += 1
                last_end = i

        prefix_sum_map[prefix_sum] = i

    return count



t = int(input())


for _ in range(t):
    n = int(input())
    lst = list(map(int, input().split()))

    print(solve(lst))