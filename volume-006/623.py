# author : the__martian
# 623
import sys

for line in sys.stdin:
    n = int(line)
    res = 1
    for i in range(1,n+1):
        res *= i 
    print("{}!".format(n))
    print(res)