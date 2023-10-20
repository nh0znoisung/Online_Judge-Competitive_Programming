[n,x] = [int(i) for i in input().split()]
a = [int(i) for i in input().split()] # len = n

# l < r
# l = 0, r = 1,n-1

# cumsum 
# F[l..r] = /a[l+1] - a[l]/ + /a[l+2] - a[l+1]/ + .. + /a[r] - a[r-1]/ (0<=l < r <= n-1)
# cum[0] = 0
# cum[i] = /A[i] - A[i-1]/ + .. + /a[1] - a[0]/ = F[0..i]

# F[l..r] = F[0..r] - F[0..l] = cum(r) - cum(l)  | l >=0

# r r + 1 ... n-1
curr = 0
cum = [0]

for i in range(1,n):
    curr += abs(a[i]-a[i-1])
    cum.append(curr)

# print(cum)

count = 0
l, r =0, 1
while l < r and r <= n-1:
    # if (cum[r] - cum[l])*(r-l) < x:
    #     r += 1
    while (cum[r] - cum[l])*(r-l) >= x and l < r:
        count += n-r
        l += 1
        # print(l, r)
    r += 1
print(count)