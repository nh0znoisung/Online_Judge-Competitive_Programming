def binary_search(arr, target):
    low, high = 0, len(arr) - 1
    result = -1

    while low <= high:
        mid = (low + high) // 2

        if arr[mid] <= target:
            result = mid
            low = mid + 1
        else:
            high = mid - 1

    return result

t = int(input())

for i in range(t):
    n, g = map(int, input().split())
    lst = []
    mn = 1e6 + 11
    mx = -1
    for _ in range(n):
        x = int(input())
        lst.append(x)
        mx = max(mx, x)
        mn = min(mn, x)
    
    lst.sort()
    
    _idx = binary_search(lst, g)

    idx, dist = -1, -1
    if _idx == -1:
        idx = n
        dist = mn - g
    elif _idx == n-1:
        idx = 1
        dist = g - mx
    else:
        # _idx in [0, n-2] => _idx + 1 in [1, n-1]
        # less index in right
        if g - lst[_idx] < lst[_idx+1] - g: # Choose left
            idx = n - _idx
            dist = g - lst[_idx]
        else: # Choose right
            idx = n - _idx - 1
            dist = lst[_idx+1] - g
    
    print(f"Case #{i + 1}: {idx} {dist}")
