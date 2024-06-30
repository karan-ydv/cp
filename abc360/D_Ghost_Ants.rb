N, T = ARGF.readline.chomp.split.map(&:to_i)

S = ARGF.readline.chomp

X = ARGF.readline.chomp.split.map(&:to_i)

a, b = X.partition.each_with_index { |x, i| S[i] == '1' }

a.sort!
b.sort!

ans = 0
for x in a
  ans += b.bsearch_index { |y| y > x + 2 * T } || b.size
  ans -= b.bsearch_index { |y| y > x } || b.size
end

puts ans
