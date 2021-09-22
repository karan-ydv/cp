def solution(A):
    n = len(A)
    H = set()
    B = []
    for i in range(0, n):
        if A[i] == 'H':
            left = i > 0 and A[i - 1] == '-'
            right = i < n - 1 and A[i + 1] == '-'
            if(left == False and right == False):
                return -1

    for i in range(0, n):
        if A[i] == 'H':
            H.add(i)
        else:
            cnt = 0
            if i > 0 and A[i - 1] == 'H':
                cnt += 1
            if i < n - 1 and A[i + 1] == 'H':
                cnt += 1
            if cnt != 0:
                B.append((cnt, i))
    
    B.sort()
    ans = 0
    while 'H' in A:
        x, i = B[-1]
        # print(x, i)
        flag = False
        if(i - 1 in H):
            H.remove(i - 1)
            flag = True
        if(i + 1 in H):
            H.remove(i + 1)
            flag = True
        if flag == True:
            ans += 1
        B.pop()

    
    if len(H) > 0:
        return -1

    return ans

print(solution("-H-HH--"))
print(solution("H"))
print(solution("HH-HH"))
print(solution("-H-H-H-H-H-"))