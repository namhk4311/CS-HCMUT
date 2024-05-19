
perfect :: Int -> [Int]
perfect n = [x | x <- [1..n], sum (factor x) == x]