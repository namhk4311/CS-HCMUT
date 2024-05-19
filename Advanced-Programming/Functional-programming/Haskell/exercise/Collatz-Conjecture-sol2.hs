module CollatzConjecture2 (collatz1) where
 

collatz1 :: Integer -> Maybe Integer
collatz1 n
    | n <= 0 = Nothing
    | n == 1 = Just 0
    | even n = fmap (+ 1) $ collatz1 (n `div` 2)
    | otherwise = fmap (+ 1) $ collatz1 (3 * n + 1)
