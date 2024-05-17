t = ARGF.readline.to_i

t.times do
  n = ARGF.readline.to_i
  arr = Array.new(n) { (1..n).to_a }
  moves = (1..n).map { |i| [1, i] }
  str = (1..n).to_a.join(' ')
  m = n
  # p *arr
  # puts

  while m > 1
    m /= 2
    if moves[-1][0] == 1
      1.upto(m) do |j|
        moves << [2, j]
        (1..n).each do |i|
          arr[i - 1][j - 1] = i
        end
      end
    else
      1.upto(m) do |i|
        moves << [1, i]
        arr[i-1] = (1..n).to_a
      end
    end
    # p *arr
    # puts
  end
  ans = arr.sum(&:sum)
  print "#{ans} #{moves.size}\n"
  moves.each { |a, b| print "#{a} #{b} #{str}\n" }
end
