from sys import stdin
from bisect import bisect_right
h, w, n = map(int, stdin.readline().strip().split())

a = sorted(tuple(map(int, stdin.readline().strip().split())) for i in range(n))

LIS = []
bk = [-1]*n

for i in range(n):
    x, y = a[i]
    idx = bisect_right(LIS, (y, ))
    if idx == len(LIS):
        LIS.append(y)
    else:
        LIS[idx] = y

print(len(LIS))

v = LIS