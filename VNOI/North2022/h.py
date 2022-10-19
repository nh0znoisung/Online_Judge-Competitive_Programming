import bisect

lst = []
n = int(input())
for i in range(n):
    s = input()
    if "IN" in s:
        ele = int(s.split()[1])
        bisect.insort(lst, ele)
    elif "OUT" in s:
        ele = int(s.split()[1])
        lst.remove(ele)
    elif "MEDIAN" in s:
        if len(lst) % 2 == 0:
            res = (lst[len(lst) // 2 ] + lst[len(lst) // 2 -1])/2    
        else:
            res = lst[len(lst) // 2]
        
        print(res)
        