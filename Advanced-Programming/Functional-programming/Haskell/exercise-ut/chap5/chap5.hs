concatenate :: [[a]] -> [a]
concatenate xss = [x | xs <- xss, x <- xs]