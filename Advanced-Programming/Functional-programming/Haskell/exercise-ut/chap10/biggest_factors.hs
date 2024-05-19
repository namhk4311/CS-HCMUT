find_gcd :: Int -> Int -> Int
find_gcd a 0 = a
find_gcd a b = gcd b (a `mod` b)

biggest_factor :: IO()
biggest_factor = do
    putStr ("Input the first number: ")
    xs <- getLine
    putStr ("Input the second number: ")
    ys <- getLine
    let x = read xs :: Int
    let y = read ys :: Int
    putStrLn ("The biggest factor of " ++ xs ++ " and " ++ ys ++ " is " ++ show(find_gcd x y))
