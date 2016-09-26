def dfs(G):
    pre = {}
    num = 0
    stack = [v for v in G.keys()]
    post = {}
    cc_num = 0
    while len(stack) > 0:
        curr = stack.pop(-1)
        if curr in post:
            continue
        elif curr in pre:
            post[curr] = num
            num += 1
        else:
            pre[curr] = num
            num += 1
            stack.append(curr)
            for w in G[curr]:
                if w not in pre:
                    stack.append(w)


    return pre, post

def dfs_cc(G, stack_order):
    pre = {}
    num = 0
    post = {}
    cc_num = 0
    cc = {}
    while len(stack_order) > 0:
        stack = [stack_order.pop(-1)]
        while len(stack) > 0:
            curr = stack.pop(-1)
            if curr in post:
                continue
            elif curr in pre:
                post[curr] = num
                num += 1
            else:
                pre[curr] = num
                if cc_num not in cc:
                    cc[cc_num] = []
                cc[cc_num].append(curr)
                num += 1
                stack.append(curr)
                for w in G[curr]:
                    stack.append(w)


        cc_num += 1
    return cc

def reverse(G):
    Gp = {}
    for v in G:
        Gp[v] = []
    for v in G:
        for e in G[v]:
            Gp[e].append(v)
    return Gp

def SCC(G):
    Gp = reverse(G)
    pre, post = dfs(Gp)
    stack = map(lambda x: x[1], sorted([(post[i], i) for i in post]))
    cc = dfs_cc(G, stack)
    return cc

def test_SCC():
    G = {}
    G[1] = [2]
    G[2] = [3]
    G[3] = [1]
    cc = SCC(G)
    print cc

    G = {}
    G[1] = [2]
    G[2] = [3]
    G[3] = [1, 4]
    G[4] = [5]
    G[5] = [6]
    G[6] = [4]
    cc = SCC(G)
    print cc

    G = {}
    G[1] = [2]
    G[2] = [3]
    G[3] = [1, 4]
    G[4] = [5]
    G[5] = [6]
    G[6] = [4, 7]
    G[7] = []
    cc = SCC(G)
    print cc

    G = {}
    G[1] = [2]
    G[2] = [3]
    G[3] = [2]
    cc = SCC(G)
    print cc

"""
TIMING TESTS
"""
def random_G(n, m):
    G = {}
    import random
    for i in range(n):
        G[i] = []
    for _ in range(m):
        i = random.randint(0, n-1)
        j = i
        while j != i:
            j = random.randint(0, n-1)
        G[i].append(j)
    return G

def time_SCC(G):
    import time
    t1 = time.time()
    cc = SCC(G)
    t2 = time.time()
    elapsedTime = t2 - t1
    return elapsedTime

if __name__ == "__main__":
    test_SCC()
    n, m = 10**5, 3 * 10**5
    G = random_G(n, m)
    t = time_SCC(G)
    print('SCC on n = {}, m = {} finished in {} ms'.format(
            n, m, int(t * 1000)))

