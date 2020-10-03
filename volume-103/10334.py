# author: the__martian
# 10334

import sys

fib = [1,2]
a = 1
b = 2
for i in range(2,1001):
    fib.append(a + b)
    t = b;
    b += a
    a = t

for line in sys.stdin:
    n = int(line)
    print(fib[n])

