sumAndDiv :: [Double] -> Double
sumAndDiv as = (foldl (+) 0 as) / (foldl (\x y -> x * cos y) 1 as)