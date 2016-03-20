--Using it because of some conflict with Prelude
import Data.Foldable as F

data Tree a = EmptyTree | Node a (Tree a) (Tree a) deriving (Show)

instance Foldable Tree where
	foldr f acc EmptyTree = acc
	foldr f acc (Node x left right) = F.foldr f (f x (F.foldr f acc right)) left

--Simple binary tree
treeInsert :: (Ord a) => a -> Tree a -> Tree a
treeInsert x EmptyTree = Node x EmptyTree EmptyTree
treeInsert x (Node a left right)
	| x == a = Node x left right
	| x < a = Node a (treeInsert x left) right
	| x > a = Node a left (treeInsert x right)

--Searching function
searchTree :: (Ord a) => (a -> Bool) -> Tree a -> Maybe a
searchTree condition = F.foldr (setFunc condition) Nothing
	where setFunc condition x acc
		| condition x = Just x
		| otherwise = acc

