from sys import stdin
from bisect import bisect_right
h, w, n = map(int, stdin.readline().strip().split())

a = sorted([tuple(map(int, stdin.readline().strip().split())) for i in range(n)] + [h, w])