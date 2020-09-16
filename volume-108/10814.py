# author : the__martian
# 10814
import sys
import  math

n = int(input())

while n:
  n -= 1
  li = input().split()
  a = int(li[0])
  b = int(li[2])
  g = math.gcd(a, b)
  a //= g 
  b //= g
  print("{} / {}".format(a, b))