posElem ::  Int -> [Int] -> Maybe Int
posElem n a = posElem' n a 0

posElem' :: Int -> [Int] -> Int -> Maybe Int
posElem' c (e:xs) b
         | c == e = Just b
         | c /= e = posElem' c (xs) (b + 1)
posElem' c [] b = Nothing
