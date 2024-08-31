from sys import stdin
from bisect import bisect_right
h, w, n = map(int, stdin.readline().strip().split())

a = [(1, 1)] + sorted(tuple(map(int, stdin.readline().strip().split())) for i in range(n)) + [(h, w)]

LIS = []
bk = [-1]*len(a)

for i in range(n+2):
    x, y = a[i]
    idx = bisect_right(LIS, (y, i))
    
    if idx == len(LIS):
        LIS.append((y, i))
    else:
        LIS[idx] = (y, i)
    
    if idx != 0:
        bk[i] = LIS[idx-1][1]

print(len(LIS) - 2)

v = LIS[-1][1]

buf = []
ans = ""

while v != -1:
    u = bk[v]
    dx = a[v][0] - a[u][0]
    dy = a[v][1] - a[u][1]

    ans = "D"*dx + "R"*dy
    v = u
print(ans)