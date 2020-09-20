# https: // www.acwing.com/problem/content/description/792/

n = float(input())
l, r = -10000, 10000.0

while r-l > 1e-12:
    mid = (l+r)/2
    if mid**3 >= n:
        r = mid
    else:
        l = mid

print("%.6f" % (l))
