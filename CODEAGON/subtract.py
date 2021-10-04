def subtract(A, B):
    x = 0
    for d in A:
        x *= 10
        x += d
    y = 0
    for d in B:
        y *= 10
        y += d
    
    x -= y
    L = [int(d) for d in str(x)]
    return L

A = [1, 2, 3]
B = [2, 3]

print(*subtract(A, B))