sumAndDiv :: [Double] -> Double
sumAndDiv as = sum' as / (foldl (\x y -> x * cos y) 1 as)

sum' :: [Double] -> Double
sum' as = foldl (+) 0 as