n, m = map(float, input().split())
while(n):
    p = float(input())
    if (p < m):
        print("On Sale! %.1d", p)
    n -= 1
