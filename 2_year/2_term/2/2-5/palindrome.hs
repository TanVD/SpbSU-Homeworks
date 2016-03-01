isPalindrome :: (Eq a) => [a] -> Bool
isPalindrome a = isPalindromeStack a [] (length a) 0

isPalindromeStack :: (Eq a) => [a] -> [a] -> Int -> Int -> Bool
isPalindromeStack [] _ _ _ = True
isPalindromeStack (x:xs) ys a b
	| (a == b + 1)  = isPalindromeStack xs (ys) (a - 1) b
	| (a > b) = isPalindromeStack xs (x:ys) (a - 1) (b + 1)
	| (a == b) = (isPalindromeStack xs ys (a - 1) (b - 1)) && (x == head(ys))  
