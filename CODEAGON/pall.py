def solutin(s):
    n = len(s)
    f = 0
    ans = ""
    begin = n
    for i in range(2 * n):
        left = i // 2
        right = left + f
        f = 1 - f
        while left >= 0 and right <= n - 1:
            if s[left] != s[right]:
                break
            left -= 1
            right += 1
        
        if right - left - 1 > len(ans):
            ans = s[left+1:right]
            begin = left
        elif right - left - 1 == len(ans):
            if begin > left:
                begin = left
                ans = s[left+1:right]
    return ans

print(solutin(input()))