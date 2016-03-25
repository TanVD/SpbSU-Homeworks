data Printed = Book {
					name :: String,
					author:: String,
					price:: Int
					}
			    | Journal 
			    	{
			    	name :: String,
			    	year :: Int,
			    	issue :: Int,
			   		price :: Int
			   	}

getPrice :: [Printed] -> Int
getPrice as = foldl funcSum 0 as
	where 
		funcSum a b = a + price(b)
		--funcSum a (Journal _  _ _ price) = a + price