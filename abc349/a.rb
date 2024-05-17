n = ARGF.readline.to_i
arr = ARGF.readline.split.map(&:to_i)

puts 0 - arr.sum
