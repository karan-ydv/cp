n = ARGF.readline.chomp.to_i

arr = []
result = []
sum = 0

n.times do |i|
  arr << ARGF.readline.split.map(&:to_i)
  result << arr[i][0]
  sum += result[i]
end

for i in 0..n-1
  break if sum >= 0

  sum += arr[i][1] - arr[i][0]
  result[i] = arr[i][1]

  if sum > 0
    result[i] -= sum
    sum = 0
  end
end


if sum == 0
  puts 'Yes'
  puts result.join(' ')
else
  puts 'No'
end
