# Jerry and Password

# Sliding window
# Tìm max của chuỗi con phân biệt( max là 9) -> Dễ

# 11
# i=0, j=1 => 11
# i=j=0 -> 1
# i=j=1 -> 1
# Xem max của nó là dài tới đâu
# i=j=n-1 là end, while i <= n-1 and j <= n-1 and i <= j

t = int(input())

for _ in range(t):
    s = input() # str
    n = len(s)
    
    i, j, ans = 0, 0, 1
    ss = set()
    ss.add(s[i])
    while i < n and j < n:
        while j < n-1 and s[j+1] not in ss:
            ss.add(s[j+1])
            j += 1
        
        ans = max(ans, j-i+1)
        ss.remove(s[i])
        i += 1

    
    print(n-ans)
