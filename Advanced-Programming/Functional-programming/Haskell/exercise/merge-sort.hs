merge :: Ord a => [a] -> [a] -> [a]
merge [] [] = []
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys) 
    | x <= y = [x] ++ merge (xs) (y:ys)
    | otherwise = [y] ++ merge (x:xs) (ys)

msort :: Ord a => [a] -> [a]
msort [] = []
msort xs 
    | length xs == 1 = xs
    | otherwise = []

halve :: Ord a => [a] -> ([a],[a])
halve xs = (take lhs xs,drop lhs xs)
    where lhs = length xs `div` 2

mergesort :: Ord a => [a] -> [a]
mergesort [] = []
mergesort [x] = [x]
mergesort xs = merge (mergesort left) (mergesort right)
    where (left,right) = halve xs

concathehe :: [[a]] -> [a]
concathehe [] = []
concathehe (x:xs) = x ++ concathehe xs

-- Define a function `replicate` that takes an integer and a value, and produces a list with the value repeated that many times.
replicatehehe :: Int -> a -> [a]
replicatehehe n x
    | n <= 0    = []       -- If n is less than or equal to 0, return an empty list.
    | otherwise = [x] ++ replicatehehe (n - 1) x  -- Otherwise, prepend x to the result of replicating (n-1) times.

twice :: (a -> a) -> a -> a 
twice f x = f (f x)

listinsert :: Int -> [Int] -> [Int]
listinsert a [] = [a]
listinsert a xs = [m | m <- xs, m < a] ++ [a] ++ [n | n <- xs, n >= a]