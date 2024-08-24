n = ARGF.readline.to_i

prev = ''
(n - 1).times do
  dish = ARGF.readline.chomp
  if prev == 'sweet' and dish == 'sweet'
    puts 'No'
    exit
  end
  prev = dish
end

puts 'Yes'