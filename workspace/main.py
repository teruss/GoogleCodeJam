def get_score(all, corners, inners, remains):
    sides = all - corners - inners
    score = min(inners, remains) * 4
    if inners >= remains:
        return score
    remains -= inners
    score += min(sides, remains) * 3
    if sides >= remains:
        return score
    return score + (remains - sides) * 2

def solve(R, C, N):
    if N <= (R * C + 1) / 2:
        return 0

    maxScore = (R - 1) * C + R * (C - 1)
    remains = R * C - N

    if R % 2 == 1 and C % 2 == 1:
        pattern1 = get_score((R * C + 1) / 2, 4, ((R - 2) * (C - 2) + 1) / 2, remains)
        pattern2 = get_score(R * C / 2, 0, (R - 2) * (C - 2) / 2, remains)
        return maxScore - max(pattern1, pattern2)

    return maxScore - get_score(R * C / 2, 2, (R - 2) * (C - 2) / 2, remains)

def result():
    R, C, N = [int(x) for x in raw_input().split()]
    return solve(R, C, N)

if __name__ == "__main__":
    T = int(raw_input())
    for t in range(1, T + 1):
        print "Case #{0}: {1}".format(t, result())
