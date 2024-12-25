with open("./input.txt", "r") as f:
    with open("./output.txt", "w") as F:
        input = f.read
        n, k = map(int, input().split())
        a = list(map(int, input().split()))
        a.sort(reverse=True)
        print(a[k-1], file = F)
        
    