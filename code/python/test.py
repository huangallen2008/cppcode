from sys import stdin
from bisect import bisect_right
h, w, n = map(int, stdin.readline().strip().split())

a = sorted(tuple(map(int, stdin.readline().strip().split())) for i in range(n)) + [(h, w)]

LIS = []
bk = [-1]*n

for i in range(n):
    x, y = a[i]
    idx = bisect_right(LIS, (y, i))
    
    if idx == len(LIS):
        LIS.append((y, i))
        bk[i] = LIS[-1][1]
    else:
        LIS[idx] = y
        bk[i] = bk[LIS[idx]][1]

print(len(LIS))

v = LIS[-1][1]

ans = ""

while v != -1:
    u = bk[v]
    dx = a[v][0] - a[u][0]
    dy = a[v][1] - a[u][1]

    ans = "D"*dx + "R"*dy + ans
    v = u