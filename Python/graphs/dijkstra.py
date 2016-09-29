__author__ = "matthewdippel"
import heapq
def dijkstra(G, n):
    if n not in G:
        raise LookupError("vertex not in graph")
    dist = {}
    pred = {}
    queue = []
    for v in G:
        if v != n:
            queue.append((float('inf'), v, -1))
    queue.append((0, n, -1))
    heapq.heapify(queue)
    while len(queue) > 0:
        d, u, p = heapq.heappop(queue)
        #if d == float('inf'):
        #    return dist, pred

        if u in dist:
            continue
        dist[u] = d
        pred[u] = p
        #if len(dist) == len(G):
        #    return dist, pred
        for v in G[u]:
            if v in dist:
                continue
            else:
                new_dist = d + G[u][v]
                heapq.heappush(queue, (new_dist, v, u))
    return dist, pred

def test():
    G = {}
    G['S'] = {'B': 24, 'D': 20, 'C': 3}
    G['B'] = {'S': 24}
    G['C'] = {'S': 3, 'D': 12}
    G['D'] = {'S': 20, 'C': 12}

    dist, pred = dijkstra(G, 'S')
    print dist, pred

def stress_test_dijkstra():
    G = {}
    N = 2000
    M = 0
    import random
    for i in range(N):
        G[i] = {}
    for i in range(N):
        for j in range(i):
            weight = random.randint(1,1000)
            G[i][j] = weight
            G[j][i] = weight
            M += 1
    import time
    t1 = time.time()
    dist, pred = dijkstra(G, 0)
    t2 = time.time()
    t = t2 - t1
    print('dijkstra on n = {}, m = {} finished in {} ms'.format(
        N, M, int(t * 1000)))


if __name__ == "__main__":
    stress_test_dijkstra()
