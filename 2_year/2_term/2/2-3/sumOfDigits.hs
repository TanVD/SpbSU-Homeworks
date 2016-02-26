{-# LANGUAGE TemplateHaskell #-}
import Data.Char

sumOfDigits :: Int -> Int
sumOfDigits a = sumOfDigitsRec a 0

sumOfDigits' :: Int -> Int
sumOfDigits' a = sumOfDigitsChar a

sumOfDigitsRec :: Int -> Int -> Int
sumOfDigitsRec 0 b = b
sumOfDigitsRec a b = sumOfDigitsRec (a `div` 10) (a `mod` 10)

sumOfDigitsChar :: Int -> Int
sumOfDigitsChar a = sum $  map  (digitToInt)  (show a)
