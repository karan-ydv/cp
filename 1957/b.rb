t = ARGF.readline.chomp.to_i

t.times do
  n, k = ARGF.readline.split.map(&:to_i)

  if n == 1
    puts k
    next
  end

  p = 1
  p *= 2 while p * 2 <= k

  arr = [p - 1, k - p + 1]

  arr += [0] * (n - 2)

  arr.each { |x| print x, ' ' }
  print "\n"

end
