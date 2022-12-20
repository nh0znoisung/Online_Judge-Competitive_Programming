import math
import sys

while(True):
    s = sys.stdin.readline().rstrip('\n')
    lst = s.split()
    a = int(lst[0])
    b = int(lst[1])
    c = int(lst[2])

    if(a == -1 and b == -1 and c == -1):
        break
    
    d = {
        "White": [255,255,255],
        "Silver": [192,192,192],
        "Gray": [128,128,128],
        "Black": [0,0,0],
        "Red": [255,0,0],
        "Maroon": [128,0,0],
        "Yellow": [255,255,0],
        "Olive": [128,128,0],
        "Lime": [0,255,0],
        "Green": [0,128,0],
        "Aqua": [0,255,255],
        "Teal": [0,128,128],
        "Blue": [0,0,255],
        "Navy": [0,0,128],
        "Fuchsia": [255,0,255],
        "Purple": [128,0,128]
    }
    res=""
    mn = 1e10
    for color,value in d.items():
        if mn > math.sqrt(abs(a-value[0])**2+abs(b-value[1])**2+abs(c-value[2])**2):
            res = color
            mn = math.sqrt(abs(a-value[0])**2+abs(b-value[1])**2+abs(c-value[2])**2)
    print(res)
        
