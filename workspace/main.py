import math

def solve(N):
    if N < 10:
        return N

    S = str(N)
    M = len(S)

    ans = 1

    for d in range(1, M):
        ans += 10 ** ((d + 1) / 2) - 1
        if d > 1:
            ans += 1
        ans += 10 ** (d / 2) - 1

    L = S[:M/2]
    R = S[M/2:]

    if int(R) == 0:
        return solve(N - 1) + 1

    if int(L[::-1]) == 1:
        return ans + int(R)

    ans += int(L[::-1])

    ans += 1

    ans += int(R) - 1
    return ans

def result():
    return solve(int(raw_input()))

if __name__ == "__main__":
    T = int(raw_input())
    for t in range(1, T + 1):
        print "Case #{0}: {1}".format(t, result())
