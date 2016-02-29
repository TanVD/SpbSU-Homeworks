checkBrackets :: String -> Bool
checkBrackets a = checkBrackets' a 0

checkBrackets' :: String -> Int -> Bool
checkBrackets' [] 0 = True
checkBrackets' [] _ = False
checkBrackets' (a:as) numberBrackets
	| a == '(' = checkBrackets' as (numberBrackets + 1)
	| (numberBrackets > 0) && (a == ')') = checkBrackets' as (numberBrackets - 1)
	| (numberBrackets == 0) && (a == ')') = False
	| otherwise = checkBrackets' as numberBrackets
