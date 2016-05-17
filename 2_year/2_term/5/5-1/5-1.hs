import qualified Data.Set as S
import qualified Data.List as L

foundSums :: Int -> IO()
foundSums n = do
    mapM_ (putStrLn . show) (createSet $ getList  n n )

getList :: Int -> Int -> [[Int]]
getList 0 _ = [[]]
getList number inc = [x : y | x <- [1 .. inc], y <- getList (number - x) (number - x)]

createSet :: [[Int]] -> S.Set [Int]
createSet [] = S.empty
createSet (a:as) = S.insert (L.sort a) (createSet as)
