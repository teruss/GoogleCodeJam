def solve(groups):
    lst = {}
    j = 0
    maxH = 0
    for D, H, M in groups:
        maxH += H

    for D, H, M in groups:
        for h in range(H):
            for i in range(maxH + 2):
                t = (M + h) * ((360 - D) + i * 360)
                if t not in lst:
                    lst[t] = []
                lst[t].append(j)
            j += 1

    c = maxH
    res = maxH
    used = []
    for item in sorted(lst):
        for h in lst[item]:
            if h not in used:
                used.append(h)
                c -= 1
            else:
                c += 1
        res = min(res, c)
        
    return res

def result():
    N = int(raw_input())
    return solve([(int(D), int(H), int(M)) for D, H, M in [raw_input().split() for _ in range(N)]])

if __name__ == "__main__":
    T = int(raw_input())
    for t in range(1, T + 1):
        print "Case #{0}: {1}".format(t, result())
