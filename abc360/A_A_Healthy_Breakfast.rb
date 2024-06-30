str = ARGF.readline().chomp

if str.index('R') < str.index('M')
    print('Yes')
else
    print('No')
end