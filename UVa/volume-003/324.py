# author: the__martian
# 324

import  sys

digit = [[0 for i in range(0,10)] for j in range(0, 367)]

def count_digit(idx, x):
  while x != 0:
    d = x % 10
    x //= 10
    digit[idx][d] += 1

f = 1

for j in range(1, 367):
  f = f * j
  count_digit(j, f)

# print(digit)

for line in sys.stdin:
  idx = int(line)
  if idx == 0:
    break
  print("{}! --".format(idx))
  print("   (0){0:5d}    (1){1:5d}    (2){2:5d}    (3){3:5d}    (4){4:5d}".format(digit[idx][0], digit[idx][1], digit[idx][2], digit[idx][3], digit[idx][4]))
  print("   (5){0:5d}    (6){1:5d}    (7){2:5d}    (8){3:5d}    (9){4:5d}".format(digit[idx][5], digit[idx][6], digit[idx][7], digit[idx][8], digit[idx][9]))

