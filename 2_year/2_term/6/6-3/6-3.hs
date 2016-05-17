data Tree = EmptyTree 
    | Node Int Tree Tree 
    deriving Show

--Inserting

treeInsert :: Int -> Tree -> Tree
treeInsert x EmptyTree = Node x EmptyTree EmptyTree
treeInsert x (Node a left right)
    | x == a = Node x left right
    | x < a = Node a (treeInsert x left) right
    | x > a = Node a left (treeInsert x right)

--Removing

treeRemove :: Int -> Tree -> Tree
treeRemove _ EmptyTree = EmptyTree
treeRemove x (Node a left right)
    | x == a = removeNode (Node a left right)
    | x < a = Node a (treeRemove x left) right
    | x > a = Node a left (treeRemove x right)

removeNode :: Tree -> Tree
removeNode (Node _ EmptyTree EmptyTree) = EmptyTree
removeNode (Node _ EmptyTree right) = right
removeNode (Node _ left EmptyTree) = left
removeNode (Node _ left right) = Node (getRight left) (removeRight left) right

getRight :: Tree -> Int
getRight (Node a left EmptyTree) = a
getRight (Node a left right) = getRight right

removeRight :: Tree -> Tree
removeRight (Node a left EmptyTree) = left
removeRight (Node a left right) = Node a left (removeRight right)

--Height

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

--Search 
treeSearch :: Tree -> Int -> Bool
treeSearch EmptyTree n = False
treeSearch (Node a left right) n
    | a == n = True
    | n < a = treeSearch left n
    | n > a = treeSearch right n

--Size
treeSize :: Tree -> Int
treeSize EmptyTree = 0
treeSize (Node _ left right) = 1 + (treeSize left) + (treeSize right)