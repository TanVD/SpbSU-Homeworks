import  Data.List

getPosByFold :: [Int] -> Int -> Maybe Int
getPosByFold as a = getIndexFirst (foldl findFunc (0, 0, a) as)
	where 
		findFunc (b, c, d) a
			| (c /= 1) && (d /= a) = (b + 1, c, d)
			| (c /= 1) && (d == a) = (b, 1, d)
			| c == 1 = (b, c, d)


getIndexFirst :: (Int, Int, Int) -> Maybe Int
getIndexFirst (_, 0, _) = Nothing
getIndexFirst (x, _, _) = Just x


--or just

getPosByElem :: Int -> [Int] -> Maybe Int
getPosByElem a as = a `elemIndex` as

