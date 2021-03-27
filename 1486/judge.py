import random
n = random.randint(1, 10)
L = random.sample(range(1, 100), n + 1)
L[0] = 0
ans = L.index(max(L))
def secondmax(l, r):
	mx = 0
	idx = None
	m = L.index(max(L[l:r + 1]))
	for i in range(l, r + 1):
		if i != m and L[i] > mx:
			mx = L[i]
			idx = i
	return idx

print(n, flush = True)
try:
	while True:
		X = input().split()
		if X[0] == '?':
			l = int(X[1])
			r = int(X[2])
			print(secondmax(l, r), flush = True)
		elif X[0] == '!':
			val = int(X[1])
			print("\nInput: ", n, sep = '\n')
			print(*L[1:])
			print("\nOutput: ", val, sep = '\n')
			print("\nAnswer:", ans, sep = '\n')
			print("\nVerdict:", end = ' ')
			if val == ans:
				print("Correct Answer", flush = True)
			else:
				print("Wrong Answer", flush = True)
			break
except:
	print("error")