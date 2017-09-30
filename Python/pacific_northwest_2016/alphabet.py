
alph = str(raw_input().strip())
n = len(alph)
LIS = [0] * (n + 1)
S = [''] + list(alph)

for i in range(1, n + 1):
    m = 0
    for k in range(1, i):
        if S[k] < S[i]:
            m = max(m, LIS[k])
    LIS[i] = 1 + m

print 26 - LIS[n]