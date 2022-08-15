n = int(input())

def check(s, up):
    cnt = 0
    for c in s:
        if c in ['a', 'e', 'i', 'o', 'u']:
            cnt += 1
            if cnt == up:
                return True
    return False


def solve(s):
    l = len(s)
    for a in range(l+1):
        for b in range(a+1, l+1):
            for c in range(b+1, l+1):
                for d  in range(c+1, l+1):
                    # after, before = s[0:a], s[d:l]
                    start, mid, end = s[a:b], s[b:c], s[c:d]
                    if start == end:
                        if check(start, 2) and check(mid, 1):
                            print("Case #{}: Spell!".format(i))
                            return
    print("Case #{}: Nothing.".format(i))

# brute-force (n^4 * n), 4 partition + check mid + start
for i in range(1,n+1):
    s = input()
    solve(s)