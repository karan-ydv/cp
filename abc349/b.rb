str = ARGF.readline.chomp

h = str.each_char.tally

good = h.values.tally.values.all? { |v| v == 2 }

puts good ? 'Yes' : 'No'
