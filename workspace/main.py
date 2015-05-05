def primes(n):
    res = []
    d = 2
    while d * d <= n:
        while n % d == 0:
            res.append(d)
            n /= d
        d += 1
    if n > 1:
        res.append(n)
    return res

def calc(a):
    twos = 0
    threes = 0
    fives = 0
    for k in a:
        p = primes(k)
        twos = max(twos, p.count(2))
        threes = max(threes, p.count(3))
        fives = max(fives, p.count(5))
    res = []
    res += [5] * fives
    res += [3] * threes
    res += [4] * (twos / 2)
    res += [2] * (twos % 2)
    if len(res) == 3:
        return res

    while len(res) < 3:
        for i in range(2, 6):
            if not i in res:
                res.append(i)
                break
    return res

def result():
    R, N, M, K = [int(x) for x in raw_input().split()]
    for r in range(R):
        products = [int(k) for k in raw_input().split()]
        print ''.join([str(i) for i in calc(products)])

if __name__ == "__main__":
    T = int(raw_input())
    for t in range(1, T + 1):
        print "Case #{0}:".format(t)
    result()
