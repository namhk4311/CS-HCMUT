scalar :: [Int] -> [Int] -> Int
scalar ms ns = sum ([x * y | (x, y) <- zip ms ns])