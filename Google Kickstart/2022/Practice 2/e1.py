n = int(input())
d = set()
l = []
_ans = 502
r,c = 0,0
def calc():
    global d,l, _ans
    ans = -1 # max
    for i in range(r):
        for j in range(c):
            if(l[i][j] == '0'):
                mn = 502 # min
                for (a,b) in d:
                    mn = min(mn, abs(i-a) + abs(j-b))
                mn = 0 if mn == 502 else mn
                ans = max(ans, mn)
    ans = 0 if ans == -1 else ans
    

    _ans = min(_ans, ans)

def solve():
    global d,l
    calc()
    for i in range(r):
        for j in range(c):
            if(l[i][j] == '0'):
                l[i][j] = '1'
                d.add((i,j))
                calc()
                l[i][j] = '0'
                d.remove((i,j))

# brute-force: O(r*c* check), check = O(r*c) * r*c, from 1 point to 1 point
# O(r^3 * c^3 * T) = 2.5*10e16 -> TLE testset2  
for ii in range(1,n+1):
    d = set()
    _ans = 502
    s = input().split()
    r,c = int(s[0]), int(s[1])
    l = []
    for i in range(r):
        s = input()
        ll = []
        for j in range(c):
            ll.append(s[j])
            if s[j] == '1':
                d.add((i,j))
        l.append(ll)    
    solve()
    _ans = 0 if _ans == 502 else _ans
    print("Case #{}: {}".format(ii, _ans))