t = ARGF.readline.to_i
t.times do
  n = ARGF.readline.to_i
  s = ARGF.readline

  ones = s.count('1')
  if ones.odd?
    puts 'NO'
  elsif ones == 2 and s.index('1') + 1 == s.rindex('1')
    puts 'NO'
  elsif 
    puts 'YES'
  end
end
