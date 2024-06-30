s, t = ARGF.readline.chomp.split

def check(s, t)
  n = s.length
  m = t.length

  for w in 1...n
    for c in 1..w
      str = ""
      for k in (0...n).step(w)
        str += s[k + c - 1].to_s
      end
      return true if str == t
    end
  end

  return false
end

if check(s, t)
  print('Yes')
else
  print('No')
end

=begin
15 4
abcd
efgh
ijkl
mno


=end