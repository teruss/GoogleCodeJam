def max_overlap(t):
    for i in range(1, len(t)):
        if t[i:] == t[0:len(t)-i]:
            return len(t) - i
    return 0

def probability(target, keyboard):
    P = 1.0
    for i in range(len(target)):
        C = keyboard.count(target[i])
        P = P * C / len(keyboard)
    return P

def solve(S, keyboard, target):
    L = len(target)
    res = 0
    P = probability(target, keyboard)
    if P > 0:
        O = max_overlap(target)
        max_copies = 1.0 + (S - L) / (L - O)
        min_copies = P * (S - L + 1)
        res = max_copies - min_copies
    return res

def result():
    K, L, S = map(int, raw_input().split())
    k = raw_input()
    l = raw_input()
    return solve(S, k, l)

if __name__ == "__main__":
    T = int(raw_input())
    for t in range(1, T + 1):
        print "Case #{0}: {1}".format(t, result())
