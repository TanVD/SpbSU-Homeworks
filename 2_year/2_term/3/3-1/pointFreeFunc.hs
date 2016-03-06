funcNotPointFree :: (Num a) => a -> [a] -> [a]
funcNotPointFree x l = map (\y -> y * x) l

funcPointFree :: (Num a) => a -> [a] -> [a]
funcPointFree = map . (*)