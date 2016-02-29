generateSequence = "1" : "7" : "9" : (zipWith (++)  (repl3 (generateSequence)) (inf3 ("1":"7":"9":[])))

inf3 [] = []
inf3 (x:y:z:xs) = x:y:z:inf3(x:y:z:xs)

repl3 [] = []
repl3 (x:xs) = x:x:x:repl3(xs)
