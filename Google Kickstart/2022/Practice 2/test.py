f = open("a.txt", "r")
line = f.readline()
while line:
    print(line)
    line = f.readline()

# print(line)