myadd :: Int -> (Int -> Int)
myadd = \x -> (\y -> x + y)

odds n = map (\x -> x*2 + 1) [0..n-1]