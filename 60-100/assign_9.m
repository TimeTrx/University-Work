p6[] =[]
p6 (x:xs) = xs ++ xs ++ p6 xs

p7 [y] = [y]
p7 (x:xs) = p7 [x] ++ (x:xs) ++ p7 xs

p8 [] = []
p8 (x:xs) = p8 xs ++ [1..#xs] ++p8 xs

p9 [] = [2]
p9 (x:xs) = p9 xs ++p9 xs

p10 n = [], if n < 1
p10 n = [1..(entier n)] ++ p10 (n/2)