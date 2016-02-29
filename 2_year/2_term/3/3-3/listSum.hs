listSum :: [Int] -> Int
listSum xs = listSum' xs 0 0 0

listSum' :: [Int] -> Int -> Int -> Int ->Int
listSum' (x:y:z:ys) n index max
	| (x + z) > max = listSum' (y:z:ys) (n + 1) (n + 1) (x + z)
	| (x + z) <= max = listSum' (y:z:ys) (n + 1) index max
listSum' _ n index max = index
