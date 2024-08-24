N, X, Y = ARGF.readline.chomp.split.map(&:to_i)

A = ARGF.readline.chomp.split.map(&:to_i).sort.reverse
B = ARGF.readline.chomp.split.map(&:to_i).sort.reverse

def count(arr, s)
  arr.each.with_index do |a, i|
    return i + 1 if a > s
    s -= a
  end
  return N
end

puts [count(A, X), count(B, Y)].min
