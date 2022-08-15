import random
import os

TC = 10

if not os.path.isdir("Testcases"):
    os.mkdir("Testcases")

for i in range(TC):
    f = open("Testcases/{}.txt".format(i), "w")
    T = random.randint(1,100)
    # T,R,C = 1,5,5
    s = str(T) + "\n"
    for j in range(T):
        R = random.randint(1,10)
        C = random.randint(1,10)
        s += "{} {}\n".format(R, C)
        cnt = 0
        for a in range(R):
            for b in range(C):
                tmp = random.randint(0,1)
                cnt += tmp
                s += str(tmp)
            s += "\n"
        
        # print(s)
        # print(cnt)
        # if cnt == 0:
        #     # print("Hello World")
        #     tmp = random.randint(0, R*C-1)
        #     row, col = tmp//C, tmp%C
        #     print(s)
        #     # s[-2] += 1
        #     print("Hello World")
    f.write(s)
    f.close()

