# author : the__martian
# 10541
import sys
import  math

n = int(input())  

for _i in range(0, n):
    li = [int(x) for x in input().split()]

    used = 0
    for _j in range(0, li[1]):
      used += li[2 + _j]
    
    if used + li[1] - 1 > li[0]:
      print(0)
    else:
      r = li[0] - used - li[1] + 1
      res = math.factorial(r + li[1]) // math.factorial(li[1]) // math.factorial(r)
      print(int(res))
    