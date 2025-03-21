t = int(input())

def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    # print(n, k, a)

    # Step 1: Get all min button
        # value = min -> 0
        # Get min * curr_size lemon
    # Step 2: Del all min = 0 button
        # value = #(value = min)
        # Get 0 lemon
    
    a.sort()
    
    count_press = 0 # Number of times press button
    count_lemon = 0 # Number of lemons actually buy

    curr_value = -1 # Diff value
    curr_index = -1 # Mark index of Diff value
    count = 0 # Number of same element
    for i in range(n):
        if a[i] != curr_value: # Different element
            # i = 0 surely diff
            if i != 0:
                # Note that: count_press >= count_lemon 

                # 100% chance to win
                count_press += curr_value * (n - curr_index) # min * size
                count_lemon += curr_value * (n - curr_index)
            
                # If pass, put down some lemon and put down some press
                if count_lemon >= k:
                    count_press -= (count_lemon - k)
                    return count_press
                
                # At most i - curr_index, for miss pressing
                count_press += i - curr_index
                
            curr_value = a[i] # Reset curr_value to current value
            count = 1 # Reset to count same to 1
            curr_index = i # Put the first diff index
        else:
            count += 1 # Increment the number of same element
    
    # For the rest count: if a[n-1] still the same
    count_press += (k - count_lemon) # Add the miss element
    return count_press

for _ in range(t):
    print(solve())
        
