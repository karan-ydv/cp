l, r = ARGF.readline.split.map(&:to_i)

x = l

arr = []

while x < r
  n = 2**60
  while n > 0
    if x % n == 0 and x + n <= r
      arr << [x, x + n]
      x += n
      break
    end
    n >>= 1
  end
end

puts arr.size
arr.each do |a, b|
  puts "#{a} #{b}"
end
