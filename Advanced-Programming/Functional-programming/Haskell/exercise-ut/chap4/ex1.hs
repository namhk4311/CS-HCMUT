mysafetail :: [x] -> [x]
mysafetail xs = if null xs then [] else tail xs

safetail1 :: [a] -> [a]
safetail1 xs = if null xs then [] else tail xs

safetail2 :: [a] -> [a]
safetail2 xs 
  | null xs   = []
  | otherwise = tail xs

safetail3 :: [a] -> [a]
safetail3 []     = []
safetail3 (_:xs) = xs

(&&) :: Bool -> Bool -> Bool
x && y = 
    if x then y else False