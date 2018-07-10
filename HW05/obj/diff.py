import sys
import operator

def print_list(lis):
	for ele in lis:
		print(ele)

def create_dict(filename, arg):
	lis = []
	with open(filename) as f:
	     for line in f:
		val = line.replace(":", " ").replace(",", "").strip().split()
		val[0] = int(val[0])
		val[2] = int(val[2])

		lis.append(list(val))

	return lis


if(len(sys.argv) != 4):
	sys.exit(0)

file1 = sys.argv[1]
file2 = sys.argv[2]
arg = int(sys.argv[3])

lis = create_dict(file1, arg)
lis_cpy = list(lis)
lis.sort(key=operator.itemgetter(arg))

	
same1 = (lis_cpy == lis)
lis2 = create_dict(file2, arg)
lis2_cpy = list(lis2)
lis2.sort(key=operator.itemgetter(arg))
same2 = (lis2_cpy == lis2)
same3 = (len(lis2) == len(lis))

if(same1  and same2 and same3):
	print("Test passed")
else:
	print("Test failed")

