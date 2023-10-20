# Virus: Méo nộp được, run to test 20, but wrong test 1. Log of test 1 is Accepted ???

n = int(input())
a = [int(i) for i in input().split()]
mod = 1e9 + 7

cum = [0]
curr = 0
# print(a)
for i in a:
    curr = (curr + i) % mod
    # print(curr)
    cum.append(curr)
# print(cum)

mat = [[0 for _ in range(n)]  for _ in range(n)]
# print(mat)
for l in range(n):
    for r in range(l+1, n):
        mat[l][r] = (mat[l][r-1] + (a[r] *  ((cum[r] - cum[l]) % mod))%mod)%mod

# print(mat)
res = 0

for k in range(1, n+1): # len
    i = 0
    while i < n:
        res = (res + mat[i][min(i+k-1, n-1)]) % mod
        i += k

print(int(res))
del res, mat, cum, curr, a, n