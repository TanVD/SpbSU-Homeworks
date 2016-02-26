reverse' :: [a] -> [a]
reverse' a = reverseUsingTmp a []

reverseUsingTmp :: [a] -> [a] -> [a]
reverseUsingTmp [] ys = ys
reverseUsingTmp (x:xs) ys = reverseUsingTmp xs (x:ys)


