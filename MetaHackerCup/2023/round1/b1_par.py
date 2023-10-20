from functools import reduce

# Partition number theory (https://en.wikipedia.org/wiki/Partition_(number_theory))
def partitions(n):
	# base case of recursion: zero is the sum of the empty list
	if n == 0:
		yield []
		return
		
	# modify partitions of n-1 to form partitions of n
	for p in partitions(n-1):
		yield [1] + p
		if p and (len(p) < 2 or p[1] > p[0]):
			yield [p[0] + 1] + p[1:]

def product(numbers: list) -> int: 
	return int(reduce(lambda x, y: x * y, numbers, 1))



par = partitions(41)
dd = {}


for ele in par:
	pro = product(ele)
	if (pro not in dd) or (len(dd[pro]) > len(ele)):
		dd[pro] = ele
			
# 44583 partition
# 3035 unique number

t = int(input())


for i in range(t):
	p = int(input())
	
	if p in dd:
		ss = str(len(dd[p]))
		for j in dd[p]:
			ss = ss + ' ' + str(j)
	else:
		ss = '-1'
	
	text = f"Case #{i+1}: " + ss
	print(text)