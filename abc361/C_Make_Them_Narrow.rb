n, k = ARGF.readline.chomp.split.map(&:to_i)
k = n - k

arr = ARGF.readline.chomp.split.map(&:to_i).sort

# STDERR.puts arr.inspect

p ((0..(n - k)).each.map { |i| arr[i+k-1] - arr[i] }).min
