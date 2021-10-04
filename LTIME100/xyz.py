TMIN = [1] * 200000
TMAX = [1] * 200000
mod = int(1e9+7)

def numberOfWays (N, MAXH, M, L, R, A, B):
    for i in range(N + N):
        TMIN[i] = 1
        TMAX[i] = MAXH
    def Maximize(a, b, x):
        l = a + N; r = b + N
        while l < r:
            if (l & 1) > 0:
                TMIN[l] = max(TMIN[l], x)
                l += 1
            if (r & 1) > 0:
                r -= 1
                TMIN[r] = max(TMIN[r], x)
            l >>= 1
            r >>= 1
    
    def Minimize(a, b, x):
        l = a + N; r = b + N
        while l < r:
            if l & 1:
                TMAX[l] = min(TMAX[l], x)
                l += 1
            if r & 1:
                r -= 1
                TMAX[r] = min(TMAX[r], x)
            l >>= 1
            r >>= 1
    
    for i in range(M):
        Minimize(L[i] - 1, R[i], B[i])
        Maximize(L[i] - 1, R[i], A[i])
    
    for i in range(N, N + N):
        j = i
        while j > 0:
            TMIN[i] = max(TMIN[i], TMIN[j])
            TMAX[i] = min(TMAX[i], TMAX[j])
            j >>= 1
    
    ans = 1
    for i in range(N, N + N):
        ans *= max(0, TMAX[i] - TMIN[i] + 1)
        ans %= mod
    return ans

T = int(input())
for _ in range(T):
    N = int(input())
    MAXH = int(input())
    M = int(input())
    L = list(map(int, input().split()))
    R = list(map(int, input().split()))
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    print(numberOfWays(N, MAXH, M, L, R, A, B))