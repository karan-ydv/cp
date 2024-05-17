def minimum_subarray_length(nums, k)
  n = nums.size
  (1..n).each do |i|
    0.upto(n - i).each do |j|
      orz = 0
      i.times { |l| orz |= nums[j + l] }
      return i if orz >= k
    end
  end
  return -1
end
