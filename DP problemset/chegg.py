class QuadTreeNode:
	"""
	Base class for a node in a quad tree
	"""

	def __init__(self) -> None:
		pass

	def tree_size(self) -> int:
		raise NotImplementedError

	def convert_to_pixels(self, width: int, height: int) -> List[List[int]]:
		raise NotImplementedError

	def preorder(self) -> str:
		raise NotImplementedError


class QuadTreeNodeEmpty(QuadTreeNode):
	"""
	An empty node represents an area with no pixels included
	"""

	def __init__(self) -> None:
		super().__init__()

	def tree_size(self) -> int:
		"""
		Note: An empty node still counts as 1 node in the quad tree
		"""
		# TODO: implement this method
		pass

def convert_to_pixels(self, width: int, height: int) -> List[List[int]]:
	"""
	Convert to a properly formatted empty list
	"""
	# Note: Normally, this method should return an empty list or a list of
	# empty lists. However, when the tree is mirrored, this returned list
	# might not be empty and may contain the value 255 in it. This will
	# cause the decompressed image to have unexpected white pixels.
	# You may ignore this caveat for the purpose of this assignment.
	return [[255] * width for _ in range(height)]

def preorder(self) -> str:
	"""
	The letter E represents an empty node
	"""
	return 'E'

class QuadTreeNodeLeaf(QuadTreeNode):
	"""
	A leaf node in the quad tree could be a single pixel or an area in which
	all pixels have the same colour (indicated by self.value).
	"""

	value: int

	def __init__(self, value: int) -> None:
		super().__init__()
		assert isinstance(value, int)
		self.value = value

	def tree_size(self) -> int:
		"""
		Return the size of the subtree rooted at this node
		"""
		# TODO: complete this method

	def convert_to_pixels(self, width: int, height: int) -> List[List[int]]:
		"""
		Return the pixels represented by this node as a 2D list

>>> sample_leaf = QuadTreeNodeLeaf(5)
>>> sample_leaf.convert_to_pixels(2, 2)
[[5, 5], [5, 5]]
"""
# TODO: complete this method

def preorder(self) -> str:
	"""
	A leaf node is represented by an integer value in the preorder string
	"""
	return str(self.value)