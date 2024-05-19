pyths :: Int -> [(Int, Int, Int)]
pyths n = [(x,y,z) | x <- [1..n], y <- [1..n], z <- [1..n], x^2 + y^2 == z^2]

hehe :: Int -> [(Int, Int, Int)]
hehe n = if n > 0 then [] else []