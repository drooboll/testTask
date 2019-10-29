import random

random.seed()

f = open("test-num", "w")

accumulator = 0
xor = 0

for i in range(0, 1024):
	num = random.randint(0, 8096)
	accumulator += num
	xor ^= num
	f.write("{}".format(num))
	if num % 2:
		f.write(" ")
	else:
		f.write("\n")

f.close()
print("SUM value: {}".format(accumulator))
print("XOR value: {}".format(xor))
