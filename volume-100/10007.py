import sys
# author : the__martian
# 10007

fac = [1]
for i in range(1, 301):
    fac.append(i * fac[i - 1])

cata = [1]
for i in range(1, 301):
    cata.append(0)
    for j in range(0, i):
        cata[i] += cata[j] * cata[i - 1 - j]

for line in sys.stdin:
    i = int(line)
    if i == 0:
        break;
    print(fac[i] * cata[i])
