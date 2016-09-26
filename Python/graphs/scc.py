def dfs(G, stack_order = None):
    pre = {}
    num = 0
    stack = stack_order
    if stack == None:
        stack = [v for v in G.keys()]
    post = {}
    cc = {}
    cc_num = 0
    while len(stack) > 0:
        curr = stack.pop(-1)
        if curr in post:
            continue
        elif curr in pre:
            post[curr] = num
            num += 1
            cc_num += 1
        else:
            pre[curr] = num
            num += 1
            cc[curr] = cc_num
            stack.append(curr)
            for w in G[curr]:
                if w not in pre:
                    stack.append(w)


    return pre, post, cc

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
    pre, post, cc = dfs(Gp)
    for i in post:
        print i, post[i]
    stack = map(lambda x: x[1], sorted([(post[i], i) for i in post]))
    print stack
    pre, post, cc = dfs(G, stack)
    for v in cc.values():
        print filter(lambda x: cc[x] == v, cc.keys())


def test():
    G = {}
    G[1] = [0]
    G[0] = [2, 3]
    G[2] = [1]
    G[3] = [4, 5]
    G[4] = []
    G[5] = [6]
    G[6] = [3]

    SCC(G)

if __name__ == "__main__":
    test()

