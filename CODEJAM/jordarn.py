import numpy as np
from PIL import Image

an_image = Image.open("tom.jpg")
an_image = an_image.resize((64, 64))

image_sequence = an_image.getdata()
image_array = np.array(image_sequence)

def fun(x):
	Y = 0.2126 * x[0] + 0.7152 * x[1] + 0.0722 * x[2]
	if Y < 128:
		return 0
	return 1

A = [fun(x) for x in image_array]

for i in range(0, 4096):
	print(A[i], end = '')
	if (i + 1) % 64 == 0:
		print()