p1 = ([1,2],"abc")

p2 = [p1,p1]


p3 = postfix 
p5 n m = True, if n*m > 6
       = False, otherwise

p6 (x:xs) (c:cs) = (x:xs), if x > c
                 = (c:cs), if c > x
