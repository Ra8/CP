class UF:
    def __init__(self, nodes):
        self.par = {}
        for n in nodes:
            self.par[n] = -1

    def _root(self, x):
        if self.par[x] < 0:
            return x
        else:
            self.par[x] = self._root(self.par[x])
            return self.par[x]

    def union(self, x, y):
        x, y = self._root(x), self._root(y)
        if x == y:
            return
        if self.par[y] < self.par[x]:
            x, y = y, x

        self.par[x] += self.par[y]
        self.par[y] = x


def time_test():
    N = 1000000
    M = 1000000
    import time
    t1 = time.time()
    uf = UF(range(N))
    import random
    for _ in range(M):
        i = random.randint(0, N-1)
        j = random.randint(0, N-1)
        uf.union(i, j)
    t2 = time.time()
    t = t2 - t1
    print('unionfind on n = {}, m = {} finished in {} ms'.format(
        N, M, int(t * 1000)))

if __name__ == "__main__":
    time_test()


