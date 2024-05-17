s = ARGF.readline.chomp
t = ARGF.readline.chomp

def subsequence(s, t)
  i = 0
  s.each_char do |c|
    if c == t[i]
      i += 1
      return true if i == t.size
    end
  end
  false
end

t.downcase!
t.delete_suffix!('x') if t.end_with?('x')
valid = subsequence(s, t)

puts valid ? 'Yes' : 'No'
