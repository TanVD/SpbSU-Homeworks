generateSequence = "1" : "7" : "9" : zipWith (++)  (repl3 generateSequence) (inf3 generateSequence)

inf3 [] = []
inf3 (x:y:z:xs) = x:y:z:inf3(x:y:z:xs)

repl3 [] = []
repl3 (x:xs) = x:x:x:repl3 xs
--It seems not possible to do it another way. We always need to add 1 or 7 or 9 which means we need to take from the head of the list