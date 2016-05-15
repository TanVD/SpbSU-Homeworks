getMults n = getMultsShow (getMultsPairs n)

getMultsShow :: [(Int, Int)] -> IO()
getMultsShow [] = return()
getMultsShow ((a, b):xs) = do 
    putStrLn (show a ++ "*" ++ show b)
    getMultsShow xs


getMultsPairs :: Int -> [(Int, Int)]
getMultsPairs n = [1..n] >>= \y -> [1..n] >>= \f ->  return (y, f)