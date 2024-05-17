t = ARGF.readline.to_i

def valid?(arr, n, c, d)
  a = arr.min
  h = arr.tally

  n.times do |i|
    x = a + c * i
    n.times do |j|
      return false if h[x].nil? or h[x].zero?
      h[x] -= 1
      x = x + d
    end
  end
 
  return true
end

t.times do
  n, c, d = ARGF.readline.split.map(&:to_i)

  arr = ARGF.readline.split.map(&:to_i)

  valid?(arr, n, c, d) ? puts('Yes') : puts('No')
end
