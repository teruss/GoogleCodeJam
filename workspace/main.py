import bisect

def solve(groups):
    j = 0
    maxH = 0
    for D, H, M in groups:
        maxH += H

    lst = []

    for D, H, M in groups:
        for h in range(H):
            t = (M + h) * (360 - D)
            bisect.insort(lst, (t, j, M + h, 0))
            j += 1

    c = maxH
    res = maxH
    used = []
    lastT = -1
    cnt = 0
    while cnt < maxH:
        t = lst[0][0]
        while t == lst[0][0]:
            current = lst[0]
            if current[1] not in used:
                used.append(current[1])
                c -= 1
            else:
                c += 1
                cnt += 1
                
            del lst[0]
            
            bisect.insort(lst, (current[0] + current[2] * 360, current[1], current[2], current[3] + 1))
        res = min(res, c)
                
    return res

def result():
    N = int(raw_input())
    return solve([(int(D), int(H), int(M)) for D, H, M in [raw_input().split() for _ in range(N)]])

if __name__ == "__main__":
    T = int(raw_input())
    for t in range(1, T + 1):
        print "Case #{0}: {1}".format(t, result())
