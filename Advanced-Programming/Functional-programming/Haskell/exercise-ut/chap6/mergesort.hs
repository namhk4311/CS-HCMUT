merge :: Ord a => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys) = m
    where
        m = if x < y then [x] ++ merge xs (y:ys) else [y] ++ merge (x:xs) ys

mergesort :: Ord a => [a] -> [a]
mergesort [] = []
mergesort xs = ms ++ ns 