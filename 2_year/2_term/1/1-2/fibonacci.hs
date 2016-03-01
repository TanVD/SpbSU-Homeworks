fibbonaci :: Integer -> Integer
fibbonaci n = fibbonaciLin 0 1 0 n

--It seems this algorithm will take linear time and constant
--memory. But i really want to see better solution in more functional way
--(with equivalent time and memory)
fibbonaciLin :: Integer -> Integer -> Integer -> Integer -> Integer
fibbonaciLin a b acc n
  | acc < n = fibbonaciLin (a + b) a (acc + 1) n
  | acc == n = a
    
    
