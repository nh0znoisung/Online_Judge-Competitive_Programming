# https://www.geeksforgeeks.org/distance-nearest-cell-1-binary-matrix/
from collections import deque
from copy import deepcopy
# append, popLeft, a[0] (queue)
# pop (stack)
import os
if not os.path.isdir("E2"):
    os.mkdir("E2")

f = open("Testcases/{}.txt".format(0), "r")
n = int(f.readline())
d = deque()
l = set()
_ans = 502
r,c = 0,0

# brute-force: O(r^2*c^2) -> BFS: O(r*c)
def calc():
    global _ans
    dq = d.copy()
    l_ = l.copy()
    # print(l_)
    count = -1 #max length can reach
    while len(dq) > 0:
        # print(dq)
        count += 1
        ll = len(dq)
        # print(l_)
        # print(ll)
        for _ in range(ll):
            (a,b) = dq[0]
            dq.popleft()
            if a < r-1 and (a+1, b) not in l_:
                l_.add((a+1, b))
                dq.append((a+1,b))
            if a > 0 and (a-1, b) not in l_:
                l_.add((a-1, b))
                dq.append((a-1,b))
            if b < c-1 and (a, b+1) not in l_:
                l_.add((a, b+1))
                dq.append((a,b+1))
            if b > 0 and (a, b-1) not in l_:
                l_.add((a, b-1))
                dq.append((a,b-1))
    # print(count)
    _ans = min(_ans, count)

def solve():
    global d,l
    calc()
    for i in range(r):
        for j in range(c):
            if (i,j) not in l:
                l.add((i,j))
                d.append((i,j))
                calc()
                l.remove((i,j))
                d.pop()

ff =  open("E2/{}.txt".format(0), "w")
sss = ""
# brute-force: O(r*c* check), check = O(r*c) BFS approach,
# O(r^2 * c^2 * T) = 3.9*1e11 (Old: 2.5*10e16) -> TLE
for ii in range(1,n+1):
    d = deque()
    _ans = 502
    s = f.readline().split()
    r,c = int(s[0]), int(s[1])
    l = set()
    for i in range(r):
        s = f.readline()
        for j in range(c):
            if s[j] == '1':
                d.append((i,j))
                l.add((i,j))
    solve()
    f.close()
    _ans = 0 if _ans == 502 else _ans
    print("Case #{}: {}".format(ii, _ans))
    # ff =  open("Testcases/{}.txt".format(0), "w")
    # ff.write("Case #{}: {}\n".format(ii, _ans))
    # ff.close()
    sss += "Case #{}: {}\n".format(ii, _ans)
ff.write(sss)
ff.close()