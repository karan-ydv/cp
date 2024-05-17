t = ARGF.readline.to_i

def solve(arr, arr2, k)
  m = arr2.size
  h = arr2.tally
  g = arr[0,m].tally

  h.default = 0
  g.default = 0

  count = g.keys.sum { |k| [h[k], g[k]].min }

  ans = count >= k ? 1 : 0

  m.upto(arr.size - 1) do |i|
    a, b = arr[i - m], arr[i]
    count -= [g[a], h[a]].min
    count -= [g[b], h[b]].min

    g[a] -= 1
    g[b] += 1

    count += [g[b], h[b]].min
    count += [g[a], h[a]].min

    ans += 1 if count >= k
  end

  ans
end

t.times do
  n, m, k = ARGF.readline.split.map(&:to_i)

  arr = ARGF.readline.split.map(&:to_i)
  arr2 = ARGF.readline.split.map(&:to_i)

  puts solve(arr, arr2, k)
end
