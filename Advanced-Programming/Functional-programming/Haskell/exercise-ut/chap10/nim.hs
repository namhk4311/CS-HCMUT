import Data.Char 
import System.IO

printBoard :: [String] -> IO()
printBoard arr = 
    loop 0 (length arr - 1)
    where
        loop start end 
            | start > end = return ()
            | otherwise = do
                putStr (show(start + 1))
                putStr ": "
                putStrLn (arr !! start)
                loop (start + 1) end

genBoard :: [Int] -> [String]
genBoard arr = loop 0 (length arr - 1)
    where 
        loop start end 
            | start > end = []
            | otherwise = genLine (arr !! start) : loop (start+1) end


genLine :: Int -> String 
genLine num = loop 1
    where
        loop start
            | start > num = []
            | start == num = "*"
            | otherwise = "* " ++ loop (start + 1)


nim :: IO() 
nim = do 
    putStrLn "Welcome to Nim game!!"
    putStr "Enter the number of heap: "
    numStr <- getLine
    let num = read numStr :: Int
    let stat = genStat num
    let board = genBoard stat
    let stat = genStat num 
    putStrLn "The initial heap: "
    printBoard board
    playing stat 0
    putStrLn "Ending the games!"

genStat :: Int -> [Int]
genStat n | n == 0 = []
          | otherwise = n : genStat (n - 1)

playing :: [Int] -> Int -> IO()
playing stat player = 
    do
        if player == 0 then do
            putStrLn "Player 1: "
        else do 
            putStrLn "Player 2: "
        putStr "Enter the index of the heap: "
        indexHeap <- getLine
        let idx = (read indexHeap :: Int) - 1
        putStr "Enter the number of stars you want to remove: "
        countingLine <- getLine
        let count = read countingLine :: Int
        let newStat = modifyElement stat count idx
        putStrLn "The current heaps: "
        printBoard (genBoard newStat)
        if checkWinner newStat then do
            putStr "Player "
            putStr (show (player + 1))
            putStr " win the games!!"
        else do 
            let newPlayer = 1 - player 
            playing newStat newPlayer

checkWinner :: [Int] -> Bool 
checkWinner xs = loop 0 (length xs - 1)
    where 
        loop start end 
            | start > end = True
            | (xs !! start) > 0 = False
            | otherwise = loop (start + 1) end 

modifyElement :: [Int] -> Int -> Int -> [Int]
modifyElement [] _ _ = []
modifyElement (x:xs) count 0 = (x - count) : xs 
modifyElement (x:xs) count n = x : modifyElement xs count (n - 1)
