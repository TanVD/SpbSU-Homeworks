main :: IO()
main = mainProcedure []

mainProcedure :: [Int] -> IO()
mainProcedure args = do
    showVariants
    variant <- getLine
    case read variant  :: Int of
        0 -> return()
        1 -> addNumber args
        2 -> removeNumber args
        3 -> printNumbers args args

showVariants :: IO()
showVariants = do
    putStrLn "Enter your choice:"
    putStrLn "0 - exit"
    putStrLn "1 - add number"
    putStrLn "2 - remove number"
    putStrLn "3 - print numbers"

addNumber :: [Int] -> IO()
addNumber list = do
    str <- getLine
    let number = read str :: Int
    mainProcedure $ resort (number : list)

removeNumber :: [Int] -> IO()
removeNumber list = do
    str <- getLine
    let number = read str :: Int
    mainProcedure $ filter (/= number) list

printNumbers :: [Int] -> [Int] -> IO()
printNumbers [] list = mainProcedure list
printNumbers (a:as) list = do
    putStrLn (" " ++ show a)
    printNumbers as list

resort :: [Int] -> [Int]
resort [] = []
resort [x] = [x]
resort (a:b:xs)
    | a < b = a:b:xs
    | otherwise = b:resort(a:xs)