t = ARGF.readline.to_i
t.times do
  n, m, k = ARGF.readline.split.map(&:to_i)
  arr = ARGF.readline.split.map(&:to_i)

  arr.unshift(0)

  y = k % m
  y = m if y.zero?
  x = (k - y) / m

  p [x, y]
  dp = Array.new(n + 1) { Array.new(x + 1, 10**18) }

  (0..n).each { |i| dp[i][0] = 0}
  
  ans = 10**18
  p arr
  (1..n).each do |i|
    # considering ith element as the last purchase day
    ans = [ans, dp[i - 1][x] * (m + y) + y * arr[i] ].min
    p [y, arr[i], x, dp[i - 1][x], dp[i - 1][x] * m, y * (arr[i] + dp[i - 1][x])]
    (1..[i, x].min).each do |j|
      dp[i][j] = [dp[i][j], dp[i - 1][j - 1] + arr[i] * j].min
    end
  end

  # p *dp

  puts ans
end
