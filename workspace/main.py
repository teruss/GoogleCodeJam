def solve(R, C, W):
    return R * (C / W) + W - 1 + (1 if C % W != 0 else 0)

def result():
    R, C, W = (int(x) for x in raw_input().split())
    return solve(R, C, W)

if __name__ == "__main__":
    T = int(raw_input())
    for t in range(1, T + 1):
        print "Case #{0}: {1}".format(t, result())
