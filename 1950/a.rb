t = ARGF.readline.to_i
t.times do
  a, b, c = ARGF.readline.split.map(&:to_i)
  if a < b and b < c
    puts "STAIR"
  elsif a < b && c < b
    puts "PEAK"
  else
    puts "NONE"
  end
end
