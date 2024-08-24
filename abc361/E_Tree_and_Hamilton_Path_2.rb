n = ARGF.readline.chomp.to_i

graph = Array.new(n + 1) { [] }
(n - 1).times do
  u, v, w, = ARGF.readline.split.map(&:to_i)
  graph[u] << [v, w]
  graph[v] << [u, w]
end

# minimum hamilton path

def dfs(graph, u, parent, dp)
  dp[u] = 0
  graph[u].each do |v, w|
    next if v == parent
    dfs(graph, v, u, dp)
    dp[u] = [dp[u], dp[v] + w].max
  end
end

dp = Array.new(n + 1, 0)
dfs(graph, 1, 0, dp)
puts dp.max