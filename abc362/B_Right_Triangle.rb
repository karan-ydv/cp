def is_right_triangle_no_pythagoras(x1, y1, x2, y2, x3, y3)
  # Vectors
  ab = [x2 - x1, y2 - y1]
  bc = [x3 - x2, y3 - y2]
  ca = [x1 - x3, y1 - y3]
  
  # Dot products
  dot1 = ab[0] * bc[0] + ab[1] * bc[1]
  dot2 = bc[0] * ca[0] + bc[1] * ca[1]
  dot3 = ca[0] * ab[0] + ca[1] * ab[1]
  
  # Check if any dot product is zero
  if dot1 == 0 || dot2 == 0 || dot3 == 0
    return 'Yes'
  else
    return 'No'
  end
end

# Example usage:
x1, y1 = ARGF.readline.split.map(&:to_i)
x2, y2 = ARGF.readline.split.map(&:to_i)
x3, y3 = ARGF.readline.split.map(&:to_i)

puts is_right_triangle_no_pythagoras(x1, y1, x2, y2, x3, y3)
