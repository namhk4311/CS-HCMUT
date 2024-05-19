module CollatzConjecture (collatz) where

collatz :: Integer -> Maybe Integer
collatz 1 = Just 0
collatz n
    | n `mod` 2 == 1 = case collatz (3 * n + 1) of 
                    Nothing -> Nothing
                    Just k -> Just (1 + k) 
    | n `mod` 2 == 0 = case collatz (n `div` 2) of
                    Nothing -> Nothing
                    Just k -> Just (1 + k)
    | otherwise = Nothing