class UF:
    def __init__(self, nodes):
        self.par = {}
        self.comp_count = 0
        for n in nodes:
            self.comp_count += 1
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
        self.comp_count -= 1
        if self.par[y] < self.par[x]:
            x, y = y, x

        self.par[x] += self.par[y]
        self.par[y] = x



n, m = map(int, raw_input().split())

grid = []

for _ in range(n):
    row = list(str(raw_input().strip()))
    grid.append(row)


nodes = []
init_island_count = 0
Q = []
for i in range(n):
    for j in range(m):
        nodes.append((i, j))
        if grid[i][j] == 'L':
            init_island_count += 1
            Q.append((i, j))

isle_UF = UF(nodes)
seen = set()

def neighbors(cell):
    row, col = cell
    if row > 0:
        yield (row-1, col)
    if row < n - 1:
        yield (row+1,col)
    if col > 0:
        yield (row, col - 1)
    if col < m - 1:
        yield (row, col + 1)

while len(Q) > 0:
    cell_x = Q.pop(0)
    seen.add(cell_x)
    for cell_y in neighbors(cell_x):
        row, col = cell_y
        if grid[row][col] in ['L', 'C']:
            isle_UF.union(cell_x, cell_y)
            grid[row][col] = 'L'
            if cell_y not in seen:
                Q.append(cell_y)

islands = set()
for i in range(n):
    for j in range(m):
        if grid[i][j] == 'L':
            islands.add(isle_UF._root((i,j)))

print len(islands)