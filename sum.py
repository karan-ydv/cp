ans = 0
x = [0] * 101
for i in range(1, 101):
    j = i
    while j <= 100:
        x[j] ^= 1
        j += i
    print(*x)

print(sum(x))
    
