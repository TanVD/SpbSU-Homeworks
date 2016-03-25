import  Data.List

--Didn't have time to add Maybe and parametrize
getPosByFold :: [Int] -> Int -> Int
getPosByFold as a = getIndexFirst (foldl findFunc (0, 0, a) as)
	where 
		findFunc (b, c, d) a
			| (c /= 1) && (d /= a) = (b + 1, c, d)
			| (c /= 1) && (d == a) = (b + 1, 1, d)
			| c == 1 = (b, c, d)


getIndexFirst :: (Int, Int, Int) -> Int
getIndexFirst (_, 0, _) = -1
getIndexFirst (x, _, _) = x - 1


--or just

getPosByElem :: Int -> [Int] -> Maybe Int
getPosByElem a as = a `elemIndex` as

