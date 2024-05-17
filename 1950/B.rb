t = ARGF.readline.to_i

t.times do
  n = ARGF.readline.to_i
  n.times do |i|
    2.times do
      n.times do |j|
        print ["##", ".."][(i+j)%2]
      end
      puts
    end
  end
end
