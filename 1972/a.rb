t = ARGF.readline.to_i

t.times do
  n = ARGF.readline.to_i
  a = ARGF.readline.split.map(&:to_i)
  b = ARGF.readline.split.map(&:to_i)

  ans, p = 0, 0
  b.each do |bi|
    if bi < a[p]
      ans += 1
    else
      p += 1  
    end
  end
  puts ans
end
