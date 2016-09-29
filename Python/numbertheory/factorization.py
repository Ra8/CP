
def sieve(maxN):
    primes = range(maxN + 1)
    i = 2
    while i*i <= maxN:
        if primes[i] == i:
            for j in xrange(i, maxN+1, i):
                if primes[j] == j:
                    primes[j] = i
        i += 1
    return primes

def factor(N, primes):
    if len(primes) < N:
        raise IndexError("not enough primes to factor")
    factors = []
    while N > 1:
        p = primes[N]
        factors.append(p)
        N = N // p
    return factors

def test():
    primes = sieve(50000)
    N = 2*3*5
    assert factor(N, primes) == [2, 3, 5], factor(N, primes)
    N = 25*25
    assert factor(N, primes) == [5, 5, 5, 5]
    N = 13 * 11 * 7 * 5 * 2 * 2 * 2
    assert factor(N, primes) == [2, 2, 2, 5, 7, 11, 13]

def time_test():
    N = 1000000
    import time
    t1 = time.time()
    primes = sieve(N)
    t2 = time.time()
    t = t2 - t1
    print('sieve on n = {} finished in {} ms'.format(
        N, int(t * 1000)))



if __name__ == "__main__":
    test()
    time_test()