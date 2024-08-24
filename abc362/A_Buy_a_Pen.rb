colors = ['Red', 'Green', 'Blue']
cost = ARGF.readline.split.map(&:to_i)
cost.delete_at(colors.index(ARGF.readline.chomp))

puts cost.min
