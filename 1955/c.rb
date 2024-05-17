t = ARGF.readline.to_i

def sunk_ships(n, k, arr)
  
  until k.zero? or arr.size < 2
    a, b = arr.first, arr.last
    if a <= b
      break if k < 2 * a - 1
      arr.shift
      arr[-1] -= a - 1
      k -= 2 * a - 1

      unless k.zero?
        arr[-1] -= 1
        arr.pop if arr[-1].zero?
        k -= 1
      end
    else
      break if k < 2 * b
      arr.pop
      arr[0] -= b
      k -= 2 * b
    end
  end

  arr.pop if arr.size == 1 and k >= arr[0]
  n - arr.size
end

t.times do
  n, k = ARGF.readline.split.map(&:to_i)

  arr = ARGF.readline.split.map(&:to_i)

  puts sunk_ships(n, k, arr)
end
