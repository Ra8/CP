def binomial(n, k):
    import math
    if k == n:
        return 1
    elif k == 1:
        return n
    elif k > n:
        return 0
    elif k == 0:
        return 1
    else:
        a = math.factorial(n)
        b = math.factorial(k)
        c = math.factorial(n - k)
        return a // (b * c)



def test_correctness():
    for n in range(1, 100):
        for k in range(1, n+1):
            assert binomial(n, k) == binomial(n-1, k) + binomial(n-1, k-1)

def test_speed():
    n = 100000
    k = 50000
    import time
    t1 = time.time()
    val = binomial(n, k)
    t2 = time.time()
    t = t2 - t1
    print('binom on n = {}, k = {} finished in {} ms'.format(
        n, k, int(t * 1000)))

if __name__ == "__main__":
    test_correctness()
    test_speed()