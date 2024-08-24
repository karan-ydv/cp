require 'algorithms'
include Containers

N, M = ARGF.readline.chomp.split.map(&:to_i)
A = ARGF.readline.split.map(&:to_i).unshift(0)

graph = Array.new(N) { [] }

M.times do
  u, v, w = ARGF.readline.split.map(&:to_i)
  graph[u] << [v, w + A[u] + A[v]]
end

distance = []

q = PriorityQueue.new
q.push([0, 0], 0)

while !queue.empty?
  u, d = queue.pop
  
  graph[u].each do |v, w|
    if distance[v].nil? || distance[v] > d + w
      distance[v] = distance[u] + w
      queue.push([v, distance[v]], -distance[v])
    end
  end
end

puts distance.shift.join(' ')