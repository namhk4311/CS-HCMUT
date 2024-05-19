product_rec :: Num a => [a] -> a
product_rec [] = 1
product_rec (n:ns) = n * product_rec(ns)

fac_rec :: Int -> Int
fac_rec 0 = 1
fac_rec n = n * fac_rec(n - 1)

length_rec :: [a] -> Int
length_rec [] = 0
length_rec (x:xs) = 1 + length_rec(xs)

reverse_rec :: [a] -> [a]
reverse_rec [] = []
reverse_rec (x:xs) = reverse_rec(xs) ++ [x]

zip_rec :: [a] -> [b] -> [(a, b)]
zip_rec [] xs = []
zip_rec xs [] = []
zip_rec (x:xs) (y:ys) = (x, y) : zip_rec xs ys

drop_rec :: Int -> [a] -> [a]
drop_rec 0 xs = xs
drop_rec x [] = []
drop_rec n (x:xs) = drop_rec (n - 1) xs

qsort :: Ord a => [a] -> [a]
qsort [] = []
qsort (x:xs) = 
    qsort smaller ++ [x] ++ qsort larger
    where 
        smaller = [a | a <- xs, a <= x]
        larger = [b | b <- xs, b > x]