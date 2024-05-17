n = 10

arr = Array.new(n) { (1..n).to_a }
p *arr

1.upto(n/2) do |i|
  (1..n).each do |j|
    arr[j - 1][i - 1] = j
  end
end
puts
p *arr
