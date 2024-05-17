t = gets.to_i

def solve(str)
  n = str.length
  
  diff_array = Array.new(n+2, 0)
  prev = 0
  str.each_char.map(&:to_i).each.with_index(1) do |x, i|
    diff_array[i] = x - prev
    prev = x
  end

  # puts
  # p str

  n.downto(2).each do |i|
    # p i
    diff_arr = diff_array.dup
    val = 0

    sum = 0
    # p [val, diff_arr.map { |x| sum += x; sum.odd? ? '1' : '0' }.join[1...-1] ]
    1.upto(n-i+1).each do |j|
      val += diff_arr[j]

      if val.even?
        diff_arr[j+i] -= 1
        diff_arr[j] += 1
        val += 1
      end

      sum = 0
      # p [val, diff_arr.map { |x| sum += x; sum.odd? ? '1' : '0' }.join[1...-1] ]
    end

    return i if (n - i + 2).upto(n).all? { |j| val += diff_arr[j]; val.odd? }
  end

  return 1
end

t.times do
  n = gets.to_i
  s = gets.chomp
  puts solve(s)
end
