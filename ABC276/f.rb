# Segment Tree
class Segtree
  attr_reader :tree, :n, :e, :op

  def initialize(length, &operator)
    @n = length
    @n <<= 1 while @n < length
    @op = operator
    @tree = Array.new(@n << 1)
    @tree2 = Array.new(@n << 1)
  end

  def update(i, x)
    i += @n
    @tree[i] += x
    while i > 1
      i >>= 1
      @tree[i] = @op.call(@tree[i << 1], @tree[i << 1 | 1])
    end
  end

  # [l, r)
  def query(l, r)
    l += n; r += n
    res = 0
    while l < r
      res = @op.call(res, @tree[l]) if l.odd?
      res = @op.call(res, @tree[r - 1]) if r.odd?
      l = (l + 1) >> 1
      r = (r - 1) >> 1
    end
    res
  end
end

n = ARGF.gets.to_i
