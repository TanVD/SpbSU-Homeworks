import Control.Monad

getAreaMax :: [Int] -> Maybe Int
getAreaMax as = foldl mplus Nothing (checkCondition as)

checkCondition :: [Int] -> [Maybe Int]
checkCondition (x:y:z:xs)
    | x < y && z < y = Just y : checkCondition (y:z:xs)
    | otherwise = Nothing : checkCondition (y:z:xs)
checkCondition _ = []