t = int(input())
for tt in range(t):
    n = int(input())
    
    ans = ""
    ended = 0

    while len(ans) < n:

        if not ended: t1 = ans + "0"
        else: t1 = "0" + ans
        print("?", t1)
        q = int(input())
        if q:
            ans = t1
            continue
        elif ended:
            ans = "1" + ans
            continue

        if not ended: t1 = ans + "1"
        print("?", t1)
        q = int(input())
        if q:
            ans = t1
            continue

        ended = 1

    print("!", ans)