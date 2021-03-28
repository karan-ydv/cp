from PIL import Image
from scipy.ndimage import zoom
import numpy as np
srcImage = Image.open("jordan.png")
grayImage = col.convert('L')
array = np.array(grayImage)
array = zoom(array, 310/174)
np.savetxt("binarized.txt", array<128, fmt="%d")