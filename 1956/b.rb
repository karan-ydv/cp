t = ARGF.readline.chomp.to_i

t.times do
  n = ARGF.readline.chomp.to_i
  cards = ARGF.readline.split.map(&:to_i)

  ans = cards.tally.count { |k, v| v == 2 }
  puts ans
end
