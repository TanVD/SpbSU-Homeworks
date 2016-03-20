checkBrackets :: String -> Bool
checkBrackets a = checkBrackets' a []

checkBrackets' :: String -> [Char] -> Bool
checkBrackets' [][] = True
checkBrackets' [] _ = False
checkBrackets' (a:as) stack
	| a `elem` brackets = checkBrackets' as (pushBracket a stack)
	| otherwise = checkBrackets' as stack
	where brackets = "()[]{}"

pushBracket :: Char -> [Char] -> [Char]
pushBracket a [] = [a]
pushBracket a (b:bs)
	| b == '(' && a == ')' = bs
	| b == '[' && a == ']' = bs
	| b == '{' && a == '}' = bs
	| otherwise = a:b:bs
