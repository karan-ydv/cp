def solution(blocks):
    n = len(blocks)
    pref = [1] * n
    suff = [1] * n
    
    for i in range(1, n):
        if(blocks[i] <= blocks[i - 1]):
            pref[i] += pref[i - 1]

    ans = pref[-1]
    for i in range(n - 2, -1, -1):
        if(blocks[i] <= blocks[i + 1]):
            suff[i] += suff[i + 1]
        ans = max(ans, pref[i] + suff[i] - 1)

    return ans

L = [int(x) for x in input().split()]
print(solution(L))