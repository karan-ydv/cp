H, W = ARGF.readline.chomp.split.map(&:to_i)
x, y = ARGF.readline.chomp.split.map(&:to_i)

grid = Array.new(H) { ARGF.readline.chomp }

x, y = x - 1, y - 1
ARGF.readline.chomp.chars.each do |c|
  case c
  when 'U'
    x -= 1 if x > 0 and grid[x - 1][y] == '.'
  when 'D'
    x += 1 if x < H - 1 and grid[x + 1][y] == '.'
  when 'L'
    y -= 1 if y > 0 and grid[x][y - 1] == '.'
  when 'R'
    y += 1 if y < W - 1 and grid[x][y + 1] == '.'
  end
end

puts("#{x + 1} #{y + 1}")