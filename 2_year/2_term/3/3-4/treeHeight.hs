
data Tree = EmptyTree | Node Int Tree Tree deriving (Show)

--Simple binary tree
treeInsert :: Int -> Tree -> Tree
treeInsert x EmptyTree = Node x EmptyTree EmptyTree
treeInsert x (Node a left right)
	| x == a = Node x left right
	| x < a = Node a (treeInsert x left) right
	| x > a = Node a left (treeInsert x right)

treeHeight :: Tree -> Int
treeHeight tree  = treeHeight' tree 0

treeHeight' :: Tree -> Int -> Int
treeHeight' EmptyTree n = n
treeHeight' (Node x left right) n 
	| leftHeight > rightHeight  = leftHeight
	| otherwise = rightHeight
	where 
		leftHeight = treeHeight' left (n + 1)
		rightHeight = treeHeight' right (n + 1)

minTreeHeight :: Tree -> Int
minTreeHeight tree = minTreeHeight' tree 0

minTreeHeight' :: Tree -> Int -> Int
minTreeHeight' EmptyTree n = n
minTreeHeight' (Node x left right) n
	| leftHeight < rightHeight = leftHeight
	| otherwise = rightHeight
	where
		leftHeight = minTreeHeight' left (n + 1)
		rightHeight = minTreeHeight' right (n + 1)