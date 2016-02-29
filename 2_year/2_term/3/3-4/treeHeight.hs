--Simple binary tree
treeInsert x EmptyTree = Node x EmptyTree EmptyTree
treeInsert x (Node a left right)
	| x == a = Node x left right
	| x < a = Node a (treeInsert x left) right
	| x > a = Node a left (treeInsert x right)

data Tree = EmptyTree | Node Int Tree Tree deriving (Show)

treeHeight tree  = treeHeight' tree 0

treeHeight' EmptyTree n = n
treeHeight' (Node x left right) n 
	| leftHeight > rightHeight  = leftHeight
	| otherwise = rightHeight
	where 
		leftHeight = treeHeight' left (n + 1)
		rightHeight = treeHeight' right (n + 1)

minTreeHeight tree = minTreeHeight' tree 0

minTreeHeight' EmptyTree n = n
minTreeHeight' (Node x left right) n
	| leftHeight < rightHeight = leftHeight
	| otherwise = rightHeight
	where
		leftHeight = minTreeHeight' left (n + 1)
		rightHeight = minTreeHeight' right (n + 1)