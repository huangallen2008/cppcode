from sys import stdin
from bisect import bisect_right
h, w, n = map(int, stdin.readline().strip().split())

a = sorted(tuple(map(int, stdin.readline().strip().split())) for i in range(n))

LIS = []
bk = [-1]*n

for i in range(n):
    x, y = a[i]
    idx = bisect_right(LIS, (y, i))
    
    if idx == len(LIS):
        LIS.append(y)
        bk[i] = LIS[-1][1]
    else:
        LIS[idx] = y
        bk[i] = bk[LIS[idx]][1]

print(len(LIS))

v = LIS[-1][1]

ans = ""

while v != -1:
    ans = "D"* + "R"* + ans