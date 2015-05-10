def solve(R, C, W):
    if C % W == 0:
        return (C / W + W - 1) * R
    return (C / W + W) * R

def result():
    r, c, w = raw_input().split()
    return solve(int(r), int(c), int(w))


if __name__ == "__main__":
    T = int(raw_input())
    for t in range(1, T + 1):
        print "Case #{0}: {1}".format(t, result())
