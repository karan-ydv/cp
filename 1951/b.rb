t = ARGF.readline.to_i
t.times do
  n, k = ARGF.readline.split.map(&:to_i)
  arr = ARGF.readline.split.map(&:to_i)
  k -= 1
  idx = arr.index { |x| x > arr[k] } || n
  if idx > k
    ans = idx - 1
  else
    arr[k], arr[idx] = arr[idx], arr[k]
    cnt = idx == 0 ? 0 : 1
    (idx...k).each do |i|
      if arr[i + 1] < arr[idx]
        cnt += 1
      else
        break
      end
    end
    ans = [cnt, idx - 1].max
  end
  puts ans
end
