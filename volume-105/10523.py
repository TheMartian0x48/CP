# author : the__martian
# 10523
import sys

for line in sys.stdin:
    li = [int(i) for i in line.split()]
    res = 0
    f = li[1]
    for i in range(1,li[0] + 1):
        res += i * f
        f *= li[1]
    print(res)