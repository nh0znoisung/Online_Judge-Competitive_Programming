t = int(input())

M = int(5e4+11)
dp = [[0,0] for _ in range(M)] # 2 * mid

for _ in range(t):
    n = int(input()) 
    lst = list(map(int, input().split()))

    mid = n//2
    
    if n%2 == 0: # Even case        
        dp[0][0] = int(lst[mid-1] == lst[mid])
        dp[0][1] = int(lst[mid-1] == lst[mid])
        
        for i in range(1, mid):
            dp[i][0] = min(
                dp[i-1][0] + (lst[mid-i-1] == lst[mid-i]) + (lst[mid+i] == lst[mid+i-1]),
                dp[i-1][1] + (lst[mid-i-1] == lst[mid+i-1]) + (lst[mid+i] == lst[mid-i])
            )

            dp[i][1] = min(
                dp[i-1][0] + (lst[mid-i-1] == lst[mid+i-1]) + (lst[mid+i] == lst[mid-i]),
                dp[i-1][1] + (lst[mid-i-1] == lst[mid-i]) + (lst[mid+i] == lst[mid+i-1])
            )

        print(min(dp[mid-1][0], dp[mid-1][1]))
    
    else: # Odd case
        dp[0][0] = int(lst[mid-1] == lst[mid]) + int(lst[mid] == lst[mid+1])
        dp[0][1] = int(lst[mid-1] == lst[mid]) + int(lst[mid] == lst[mid+1])
        
        for i in range(1, mid):
            dp[i][0] = min(
                dp[i-1][0] + (lst[mid-i-1] == lst[mid-i]) + (lst[mid+i+1] == lst[mid+i]),
                dp[i-1][1] + (lst[mid-i-1] == lst[mid+i]) + (lst[mid+i+1] == lst[mid-i])
            )

            dp[i][1] = min(
                dp[i-1][0] + (lst[mid-i-1] == lst[mid+i]) + (lst[mid+i+1] == lst[mid-i]),
                dp[i-1][1] + (lst[mid-i-1] == lst[mid-i]) + (lst[mid+i+1] == lst[mid+i])
            )

        print(min(dp[mid-1][0], dp[mid-1][1]))