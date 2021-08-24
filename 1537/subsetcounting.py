mod = 1000000007

P = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
X = [2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 17, 19, 21, 22, 23, 26, 29, 30]
Y = [False] * (1 << 18)
Q = [0] * 18

for i in range(18):
    Q[i] = 1 << i

for i in range(1, 1 << 18):
    p = 1
    for j in range(18):
        if(i & Q[j] != 0):
            p *= X[j]
    
    for j in P:
        cnt = 0
        while p % j == 0:
            cnt += 1
            p //= j
        if cnt > 1:
            break
    else:
        Y[i] = True
        

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    F = [0] * 31
    for x in A:
        F[x] += 1
    ans = 0
    for i in range(1 << 18):
        if Y[i] == True:
            cnt = 1
            for j in range(18):
                if(i & Q[j] != 0):
                    cnt = cnt * F[X[j]] % mod
            ans = (ans + cnt) % mod
    print(ans)