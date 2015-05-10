def solve(S, k, l):
    for c in l:
        if c not in k:
            return 0
    K = len(k)
    L = len(l)
    overlap = L - 1
    for x in range(1, L):
        if l[x:] != l[:L-x]:
            overlap -= 1
        else:
            break
    print overlap
    bananas = (S - L) / (L - overlap) + 1
    print bananas
    ans = 0
    x = 0
    while x + L <= S: 
        res = 1
        for c in l:
            res *= float(k.count(c)) / K
        ans += res
        x += L - overlap
        print x, ans, L, overlap
    return bananas - ans

def result():
    K, L, S = (int(x) for x in raw_input().split())
    k = raw_input()
    l = raw_input()
    return solve(S, k, l)

if __name__ == "__main__":
    T = int(raw_input())
    for t in range(1, T + 1):
        print "Case #{0}: {1}".format(t, result())
