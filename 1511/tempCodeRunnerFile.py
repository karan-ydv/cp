import string, random
def id_generator(size, chars):
	return ''.join(random.choice(chars) for _ in range(size))

n, k = [int(x) for x in input().split()]
print(id_generator(n, string.ascii_lowercase[:k]))