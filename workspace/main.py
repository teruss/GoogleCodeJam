def isqrt(x):
    l = 0
    r = x
    while r - l > 1:
        mid = (l + r) / 2
        if mid * mid > x:
            r = mid
        else:
            l = mid
    return l

def calc(r, t):
    x = 4*r*r-4*r+1+8*t
    return (-(2*r-1)+ isqrt(x)) / 4;

def solve():
    r, t = [int(x) for x in raw_input().split()]
    return calc(r, t)

if __name__ == "__main__":
    T = int(raw_input())
    for t in range(1, T + 1):
        print "Case #{0}: {1}".format(t, solve())
