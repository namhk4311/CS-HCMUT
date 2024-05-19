quicksort :: Ord a => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = 
    quicksort ms ++ [x] ++ quicksort ns 
    where 
        ms = [a | a <- xs, a <= x]
        ns = [b | b <- xs, x < b]