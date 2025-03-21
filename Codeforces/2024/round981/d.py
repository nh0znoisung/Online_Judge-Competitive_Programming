t = int(input())

M = int(1e5 + 11)
cum = [0] * M

# dict of index
# defragmentation to interval and call max

for _ in range(t):
    n = int(input())
    lst = list(map(int, input().split()))

    dd = {0: [-1]}
    intervals = []

    for i in range(n):
        cum[i+1] = cum[i] + lst[i]
        if cum[i+1] not in dd: # len = 0
            dd[cum[i+1]] = [i]
        else:
            if len(dd[cum[i+1]]) == 1:
                dd[cum[i+1]].append(i)
                # print(dd[cum[i+1]])
                intervals.append([dd[cum[i+1]][0] , dd[cum[i+1]][1]])
            elif len(dd[cum[i+1]]) == 2:
                dd[cum[i+1]][0] = dd[cum[i+1]][1]
                dd[cum[i+1]][1] = i
                intervals.append([dd[cum[i+1]][0] , dd[cum[i+1]][1]])

    if len(intervals) == 0:
        print(0)
        continue
    
    intervals.sort(key=lambda x: (x[1]-x[0], x[0]))


    m = len(intervals)
    count = 0
    curr_end = -100
    for i in range(m):
        if intervals[i][0] > curr_end: # new interval
            curr_end = max(curr_end, intervals[i][1])
            count += 1
            continue
            
    print(count)
    
    
    