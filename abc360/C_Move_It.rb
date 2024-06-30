n = ARGF.readline.to_i

A = ARGF.readline.split.map(&:to_i)
W = ARGF.readline.split.map(&:to_i)

# p A.each_index.group_by { |i| A[i] - 1 }
# p A.each_index.group_by { |i| A[i] - 1 }.map { |k, v| (v.sum{ |i| W[i] }) }
# p A.each_index.group_by { |i| A[i] - 1 }.map { |k, v| (v.map{ |i| W[i] }).max }
cost = A.each_index.group_by { |i| A[i] - 1 }.sum { |k, v| (v.sum{ |i| W[i] }) - (v.map{ |i| W[i] }).max }

print(cost)