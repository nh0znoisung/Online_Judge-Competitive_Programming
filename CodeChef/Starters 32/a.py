def main():
    a = 0
    b = 1
    c= 4
    def sub2(b,c,f):
        return (f(c) - f(b)) * 2
    def sub1(a):
        nonlocal b
        def sub3(b):
            return b*c+a
        b = sub2(1,2,sub3)
    sub1(3)
    print(b)

main()
