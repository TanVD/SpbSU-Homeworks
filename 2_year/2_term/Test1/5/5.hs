data Printed = Book String String Int | Journal String Int Int Int

getPrice :: [Printed] -> Int
getPrice as = foldl funcSum 0 as
	where 
		funcSum a (Book _ _ price) = a + price
		funcSum a (Journal _  _ _ price) = a + price