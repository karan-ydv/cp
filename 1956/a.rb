t = ARGF.readline.chomp.to_i

t.times do
  n = ARGF.readline.to_i
  a = ARGF.readline.split.map(&:to_i)
 
  ans = 0

  a.tally.each do |k, v|
    ans += v / 3
  end

  puts ans

end
