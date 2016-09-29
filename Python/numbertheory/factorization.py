
def sieve(max_n):
    primes = range(max_n + 1)
    i = 2
    while i*i <= max_n:
        if primes[i] == i:
            for j in xrange(i, max_n+1, i):
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

def bruteforce_is_prime(n):
    """
    Return smallest prime divisor of n
    If returns n, then n is prime
    :param n:
    :return:
    """
    if n % 2 == 0:
        return 2
    if n % 3 == 0:
        return 3
    i = 5
    while i*i <= n:
        if n % i == 0:
            return i
        i += 2
        if n % i == 0:
            return i
        i += 4
    return n


def test():
    primes = sieve(50000)
    N = 2*3*5
    assert factor(N, primes) == [2, 3, 5], factor(N, primes)
    N = 25*25
    assert factor(N, primes) == [5, 5, 5, 5]
    N = 13 * 11 * 7 * 5 * 2 * 2 * 2
    assert factor(N, primes) == [2, 2, 2, 5, 7, 11, 13]

    N = 10**6
    primes = sieve(N)
    factors = factor(N, primes)
    assert factors == [2]*6 + [5]*6

    primes = sieve(1000)
    for i in range(2, 1000):
        assert bruteforce_is_prime(i) == primes[i]
    print "basic tests passed"

def compare_to_bruteforce(n):
    """
    brute forcing a single number to check primality is faster than doing sieve
    if you need to do factorization or lots of prime checking, sieve is probably
    amortized faster
    :param n:
    :return:
    """
    import time
    t1 = time.time()
    primes = sieve(n)
    p1 = primes[n]
    print p1
    t2 = time.time()
    t = t2 - t1

    s1 = time.time()
    p2 = bruteforce_is_prime(n)
    assert p2 == p1
    s2 = time.time()
    s = s2 - s1
    print('sieve on n = {} finished in {} ms'.format(
        n, int(t * 1000)))
    print('bruteforce on n = {} finished in {} ms'.format(
        n, int(s * 1000)))

def time_test():
    N = 100000
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
    n = 5915587
    compare_to_bruteforce(n)