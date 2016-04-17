generateSimple :: [Int]
generateSimple = [x |  x <- [2..], isSimple x ]

isSimple :: Int -> Bool
isSimple x = isSimpleHelp x (x - 1)
	where 
		isSimpleHelp x 1 = True
		isSimpleHelp x y = (x `mod` y /= 0) && isSimpleHelp x (y - 1)