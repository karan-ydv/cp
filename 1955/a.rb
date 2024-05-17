t = ARGF.readline.to_i
t.times do
  n, a, b = ARGF.readline.split.map(&:to_i)

  if 2 * a <= b
    puts a * n
  else
    puts b * (n / 2) + a * (n % 2)
  end
end
