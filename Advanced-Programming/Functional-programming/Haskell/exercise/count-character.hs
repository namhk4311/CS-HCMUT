count_char :: String -> Char -> Int
count_char xs n = length ([x | x <- xs, x == n])