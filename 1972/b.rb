t = ARGF.readline.to_i

t.times do
  n = ARGF.readline.to_i
  s = ARGF.readline.chomp

  if s.count('U').odd?
    puts 'Yes'
  else
    puts 'No'
  end
end
