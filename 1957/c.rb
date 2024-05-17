N = (3e1 + 69).to_i
MOD = (1e9 + 7).to_i

fact = Array.new(N + 1, 1)
inv_fact = Array.new(N + 1, 1)
power = Array.new(N + 1, 2)
double_fact = Array.new(N + 1, 1)

power[0] = 1
double_fact[0] = 1

(2..N).each do |i|
  power[i] = power[i - 1] * 2 % MOD
  double_fact[i] = double_fact[i - 2] * i % MOD
  fact[i] = fact[i - 1] * i % MOD
end

inv_fact[N] = fact[N].pow(MOD - 2, MOD)
(1...N).reverse_each do |i|
  inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD
end

def nCr(n, r, fact, inv_fact)
  return 1 if r == 0
  return n if r == 1

  fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD
end

dp = Array.new(N, 0)
dp[1] = dp[0] = 1

(2...N).each do |n|
  range = n.odd? ? (1..n) : (0..n)
  range.step(2).each do |i|
    dp[n] += nCr(n, i, fact, inv_fact) * double_fact[i - 2] % MOD * power[(n - i) / 2] % MOD
  end
end

t = ARGF.readline.chomp.to_i

t.times do
  n, k = ARGF.readline.split.map(&:to_i)

  k.times do
    r, c = ARGF.readline.split.map(&:to_i)
    n -= r == c ? 1 : 2
  end

  puts dp[n]
end
