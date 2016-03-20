--Using monads
checkUnique :: (Eq a) => [a] -> Bool
checkUnique as = length (filter (\[a, b] -> a == b) (createAllPairs as)) == length as

--Creating all possible pairs. If all elements are unique, there will be number of repeating elements equal to length of list
createAllPairs :: [a] -> [[a]]
createAllPairs as = do
	a <- as
	b <- as
	return [a, b]

--another variant usin elem

checkUnique' :: (Eq a) => [a]  -> Bool
checkUnique' [] = True
checkUnique' (a:as) = (a `notElem` as) && checkUnique as
