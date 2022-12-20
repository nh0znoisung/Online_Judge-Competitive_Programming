s = input()

l  = list(map(lambda x: float(x), s.split()))
# print(l)

A = [l[0], l[1]]
B = [l[2], l[3]]
C = [l[4], l[5]]
R = l[6]
P = l[7]

import math
def main():
    if A[0] == B[0]:
        print("NO")
        return
    
    a = (A[1] - B[1])/(A[0] - B[0])
    b = (A[0]*B[1] - A[1]*B[0])/(A[0] - B[0])

    dis = abs(a*C[0] - C[1] + b)/math.sqrt(a**2+1)
    
    per = 0
    if(dis >= R):
        per = 0
    else:
        angle = math.acos(dis/R) * 2
        area = math.pi * R**2
        # print(area)
        arc = area/(math.pi * 2) * angle
        # print(arc)
        AB = math.sqrt(R**2 - dis**2) * 2
        # print(AB)
        tri = AB * dis / 2
        # print(tri)
        res = arc - tri
        # print(res)
        per = res/area * 100

    if(per > 50):
        per = 100-per

    #print(per)
    if per <= P + 5 and per >= P - 5:
        print("YES")
        return
    else:
        print("NO")
        return



main()