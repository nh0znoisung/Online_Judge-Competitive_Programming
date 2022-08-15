from collections import deque
import math

n = int(input())

# BFS approach, O(r*c* check), Check 2 pointers O(r+c)
# Time O(r*c*(r+c) * T)
# Check, will range the unsampling points into the square constrained by y+x = mx1, y+x = mn1, y-x = mx2, y-x = mn2
# ceil(max(mx1-mn1, mx2-mn2)/2) = size of BFS
for ii in range(1,n+1):
    d = deque() # queue (x,y) # BFS copy
    dd1, dd2 = {}, {} # remaining points plus, minus
    s = input().split()
    r,c = int(s[0]), int(s[1])
    l = set() # set of(x,y) -> visited
    for i in range(r):
        s = input()
        for j in range(c):
            if s[j] == '1':
                d.append((i,j))
                l.add((i,j))
            else:
                if dd1.get(i+j) is None:
                    dd1[i+j] = {(i,j)}
                else:
                    dd1[i+j].add((i,j))
                
                if dd2.get(j-i) is None:
                    dd2[j-i] = {(i,j)}
                else:
                    dd2[j-i].add((i,j))
    mx1, mn1, mx2, mn2 = r+c-2, 0, c-1, 1-r
    count = -1 #max length can reach
    # ok = False
    while len(d) > 0:
        count += 1
        ll = len(d)
        while (dd1.get(mx1) is None or len(dd1[mx1]) == 0) and mx1 > mn1:
            mx1 -= 1
        
        while (dd1.get(mn1) is None or len(dd1[mn1]) == 0) and mn1 < mx1:
            mn1 += 1

        while (dd2.get(mx2) is None or len(dd2[mx2]) == 0) and mx2 > mn2:
            mx2 -= 1
        
        while (dd2.get(mn2) is None or len(dd2[mn2]) == 0) and mn2 < mx2:
            mn2 += 1
        square = math.ceil(max(mx1-mn1, mx2-mn2)/2)
        if count >= square:
            print("Case #{}: {}".format(ii, count))
            # ok = True
            break

        for _ in range(ll):
            (a,b) = d[0]
            d.popleft()
            if a < r-1 and (a+1, b) not in l:
                l.add((a+1, b))
                d.append((a+1,b))
                dd1[a+b+1].remove((a+1,b))
                dd2[b-a-1].remove((a+1,b))
            if a > 0 and (a-1, b) not in l:
                l.add((a-1, b))
                d.append((a-1,b))
                dd1[a+b-1].remove((a-1,b))
                dd2[b-a+1].remove((a-1,b))
            if b < c-1 and (a, b+1) not in l:
                l.add((a, b+1))
                d.append((a,b+1))
                dd1[a+b+1].remove((a,b+1))
                dd2[b+1-a].remove((a,b+1))
            if b > 0 and (a, b-1) not in l:
                l.add((a, b-1))
                d.append((a,b-1))
                dd1[a+b-1].remove((a,b-1))
                dd2[b-1-a].remove((a,b-1))
    # if not ok:
    #     print("Case #{}: {}".format(ii, count))
