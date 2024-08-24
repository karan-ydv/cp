cube1 = ARGF.readline.chomp.split.map(&:to_i).each_slice(3).to_a # (0 1 2) -> (3 4 5)
cube2 = ARGF.readline.chomp.split.map(&:to_i).each_slice(3).to_a # (5 6 7) -> (8 9 10)


if 3.times.all? { |i| cube1[0][i] < cube2[1][i] && cube1[1][i] > cube2[0][i] }
  puts 'Yes'
else
  puts 'No'
end
