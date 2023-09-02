gets.to_i.times do
  n = gets.to_i
  a = gets.chomp.chars.map(&:to_i)
  (n - 1).times { |i| a[i + 1] += a[i] }
  n.times { |i| a[i] -= i }
  t = a.tally
  t.reduce(t[0] || 0) { |s, (_, v)| s + v * (v - 1) / 2 }.tap { |r| puts r }
end
