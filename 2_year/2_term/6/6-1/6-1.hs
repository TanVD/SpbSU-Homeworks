newtype Polynomial = Polynomial [Int]

instance Num Polynomial where
    (+) (Polynomial a) (Polynomial b) = Polynomial (zipWith (+) a b)
    (-) (Polynomial a) (Polynomial b) = Polynomial (zipWith (-) a b)
    (*) (Polynomial a) (Polynomial b) = Polynomial (multiplyInt a b)

    abs  (Polynomial a) = Polynomial (map abs a)
    negate (Polynomial a) = Polynomial (map negate a)
    fromInteger = error "error"
    signum = error "error" 


multiplyInt :: [Int] -> [Int] -> [Int]
multiplyInt [] (_:ys) = 0 : multiplyInt [] ys
multiplyInt _ [] = []
multiplyInt (x : xs) ys = zipWith (+) (map (x *) ys ++ replicate (length  xs) 0) (0 : multiplyInt xs ys)



instance Show Polynomial where
    show (Polynomial []) = ""
    show (Polynomial (a:[]))
        | a == 0 = ""
        | otherwise = show a
    show (Polynomial (a:as))
        | a == 0 = 
            "" ++
            show (Polynomial as)
        | a == 1 && (as /= replicate (length as) 0) =
            "X" ++
            (condChar (length as == 1)  ""  ("^" ++ show (length as)) ) ++
            "+" ++
            show (Polynomial as)
        | a == 1 =
            "X" ++
            (condChar (length as == 1)  ""  ("^" ++ show (length as)) ) 
        | as /= replicate (length as) 0 = 
            show a ++
            "*X" ++
            (condChar (length as == 1)  ""  ("^" ++ show (length as)) ) ++
            "+" ++
            show (Polynomial as)
        | otherwise = 
            show a ++
            "*X" ++
            (condChar (length as == 1)  ""  ("^" ++ show (length as)) ) 


condChar :: Bool -> String -> String -> String
condChar True a _ = a 
condChar False _ b = b    