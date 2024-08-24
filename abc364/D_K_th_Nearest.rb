N, Q = ARGF.readline.chomp.split.map(&:to_i)
A = ([1e9] + ARGF.readline.chomp.split.map(&:to_i)).sort

# no of points within distance x from b
def count(b, x)
  (A.bsearch_index { |a| a > b + x }) - (A.bsearch_index { |a| a >= b - x })
end

Q.times do
  b, k = ARGF.readline.chomp.split.map(&:to_i)
  l, r = 0, 2 * 10**8
  
  ans = nil
  while l <= r
    x = (l + r) / 2
    if count(b, x) >= k
      ans = x
      r = x - 1
    else
      l = x + 1
    end
  end
  
  puts ans
end
