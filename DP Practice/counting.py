import sys
A = [0] * 1004

A[0] = 1
A[1] = 2
A[2] = 5

for i in range(3, 1004):
	A[i] += 2 * A[i - 1]
	A[i] += A[i - 2]
	A[i] += A[i - 3]
for n in map(str.rstrip, sys.stdin):
	n = int(n)
	print(A[n])