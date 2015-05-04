def calc(a):
    x = [s.rfind('1') for s in a]
    res = 0
    for i in range(len(x)):
        for j in range(i, len(x)):
            if x[j] <= i:
                for k in range(j, i, -1):
                    x[k], x[k - 1] = x[k - 1], x[k]
                res += j - i
                break
    return res

def result():
    return calc([raw_input() for x in range(int(raw_input()))])

if __name__ == "__main__":
    T = int(raw_input())
    for t in range(1, T + 1):
        print "Case #{0}: {1}".format(t, result())
