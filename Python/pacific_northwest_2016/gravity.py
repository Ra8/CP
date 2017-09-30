def shift(column):
    results = []
    for region in column.split('#'):
         top = region.count('.')
         bot = region.count('o')
         results.append(top*'.' + bot*'o')
    return '#'.join(results)

def transpose(grid):
     t = []
     for i in range(len(grid[0])):
         row = ''.join([grid[j][i] for j in range(len(grid))])
         t.append(row)
     return t

n, m = map(int, raw_input().split())

grid = []
for _ in range(n):
     grid.append(raw_input().strip())

grid2 = transpose(grid)

fixed_grid2 = [shift(col) for col in grid2]

fixed_grid = transpose(fixed_grid2)

for r in fixed_grid:
     print r