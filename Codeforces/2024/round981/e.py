def solve(n, permutation):
    visited = [False] * (n + 1)  # To track visited indices
    operations = 0

    # Function to find and mark a cycle
    def find_cycle(start):
        cycle = []
        current = start

        # Traverse the cycle
        while not visited[current]:
            cycle.append(current)
            visited[current] = True
            current = permutation[current - 1]  # Go to the next index in the permutation

        return cycle

    for i in range(1, n + 1):
        if not visited[i]:
            cycle = find_cycle(i)

            # If the cycle length is greater than 2, we need one operation
            if len(cycle) > 2:
                operations += 1

    return operations


t = int(input())

for _ in range(t):
    n = int(input())
    lst = list(map(int, input().split()))

    print(solve(n, lst))