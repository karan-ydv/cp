N, K, X = ARGF.readline.chomp.split.map(&:to_i)
arr = ARGF.readline.chomp.split.map(&:to_i)

arr.insert(K, X)

print(arr.join(' '))