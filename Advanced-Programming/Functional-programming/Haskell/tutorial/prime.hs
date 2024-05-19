factor :: Int -> [Int]
factor n = [x | x <- [1..n], n `mod` x == 0]

prime :: Int -> Bool
prime n = factor n == [1,n] 

listPrime :: Int -> [Int]
listPrime n = [x | x <- [2..n], prime x == True]