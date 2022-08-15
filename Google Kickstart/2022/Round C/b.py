n = int(input())

def partition(N, PartitionSum):
    assert(N >= 0 and PartitionSum >= 0)
    if (PartitionSum == 0 or N == 0):
        return []
    if(N > PartitionSum):
        return partition(N-1, PartitionSum)
    else:
        return [N] + partition(N-1, PartitionSum-N)

for i in range(1, n+1):
    [a,b,c] = [int(i) for i in input().split()]
    if (a*(a+1)/2)%(b+c) == 0:
        s = "POSSIBLE" 
        print("Case #{}: {}".format(i, s))
        arr = partition(a, (a*(a+1)/2)/(b+c)*b)
        print(len(arr))
        for ii in arr:
            print(ii, end=" ")
        print()
    else:
        s = "IMPOSSIBLE"
        print("Case #{}: {}".format(i, s))
    

    