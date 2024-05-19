merge :: Ord a => [a] -> [a] -> [a]
merge [] [] = []
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys) 
    | x <= y = [x] ++ merge (xs) (y:ys)
    | otherwise = [y] ++ merge (x:xs) (ys)

halve :: Ord a => [a] -> ([a],[a])
halve xs = (take lhs xs,drop lhs xs)
    where lhs = length xs `div` 2

mergesort :: Ord a => [a] -> [a]
mergesort [] = []
mergesort [x] = [x]
mergesort xs = merge (mergesort left) (mergesort right)
    where (left,right) = halve xs
