import math
import os.path

def createP(A):
    def createB(a):
        m = {}
        for y in range(1 << len(a)):
            l = 1
            for k in range(len(a)):
                l *= a[k] if (y & (1 << k)) != 0 else 1
            if l not in m:
                m[l] = 0
            m[l] += 1
        return m
    return [createB(a) for a in A]

def createA(A, c, N, M):
    if len(c) == N:
        A.append(list(c))
        return
    for x in range(2 if len(c) == 0 else c[-1], M + 1):
        c.append(x)
        createA(A, c, N, M)
        del c[-1]

def Pr(N, M, A):
    nf = math.factorial(N)
    mn = math.pow(M - 1, N)
    k = nf / mn
    def count_factorial(x):
        res = 1
        for i in range(2, M + 1):
            res *= math.factorial(x.count(i))
        return res
    return [k / count_factorial(a) for a in A]

def update(PrA, p, k):
    return [pra * (pp[k] if k in pp else 0) for (pra, pp) in zip(PrA, p)]
        
def calc(N, M, a, A, p, PrA):
    for k in a:
        PrA = update(PrA, p, k)
    return A[PrA.index(max(PrA))]

def result():
    R, N, M, K = [int(x) for x in raw_input().split()]
    A = []
    createA(A, [], N, M)
    PrA = Pr(N, M, A)
    p = createP(A)        

    for r in range(R):
        products = [int(k) for k in raw_input().split()]
        print ''.join([str(i) for i in calc(N, M, products, A, p, list(PrA))])

if __name__ == "__main__":
    T = int(raw_input())
    for t in range(1, T + 1):
        print "Case #{0}:".format(t)
    result()
