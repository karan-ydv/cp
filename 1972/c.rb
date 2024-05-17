t = ARGF.readline.to_i

t.times do
  n, k = ARGF.readline.split.map(&:to_i)
  a = ARGF.readline.split.map(&:to_i)

  ans = 0

  lo, hi = a.min, 10 ** 12 + 1

  while lo < hi
    mid = (lo + hi) / 2

    sum = 0
    a.each do |ai|
      sum += mid - ai if ai < mid
    end

    if sum > k
      hi = mid
    else
      lo = mid + 1
    end
  end
  

  m = hi - 1
  sum1 =  a.sum
  a.map! { |ai| ai < m ? m : ai }
  sum2 = a.sum
  
  k -= sum2 - sum1
  k += a.count { |ai| ai > m }

  puts m * n - (n - 1) + k
end

=begin
6 5 8

312 312 312 312 312 31 33
=end
