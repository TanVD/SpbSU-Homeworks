countEven :: [Int] -> Int
countEven = length' . filter (\x -> x `mod` 2 == 0)

countEven' :: [Int] -> Int
countEven' = sum' . map func
	where func x
		| x `mod` 2 == 0 = 1
		| otherwise = 0

countEven'' :: [Int] -> Int
countEven'' = foldr func 0
	where func x acc
		| x `mod` 2 == 0 = acc + 1
		| otherwise = acc

--Own implementation of sum and length using map and foldr
sum' :: [Int] -> Int
sum' as = foldr (+) 0 as

length' :: [Int] -> Int
length' as = sum' $ map (const 1) as