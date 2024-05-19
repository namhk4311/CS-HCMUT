act :: IO (Char,Char)
act = do 
    x <- getChar
    getChar
    y <- getChar
    return (x,y)

getline :: IO String
getline = do 
    x <- getChar
    if x == '\n' then 
        return [] 
    else
        do xs <- getline
           return (x:xs)

getInt :: IO Int 
getInt = readLn

factor :: Int -> [Int]
factor n = [x | x <- [1..n], n `mod` x == 0]

prime :: Int -> Bool
prime n = factor n == [1,n]

--method 1:
checkprimenum :: IO ()
checkprimenum = do
    putStr("Input a number: ")
    x <- readLn
    if prime x then
        putStrLn(show(x) ++ " is a prime")
    else 
        putStrLn(show(x) ++ " is not a prime") 

--method 2:
primeNum :: IO()
primeNum = do 
    putStr "Input a number: "
    xs <- getLine
    let x = read xs :: Int
    if (prime x) then putStrLn (xs ++ " is a prime number")
    else putStrLn (xs ++ " is Not a prime number")