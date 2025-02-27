class Solution
{
public:
  vector<int> par, group_size;

  void dsu_init(int n)
  {
    par.resize(n);
    group_size.resize(n, 1);
    for (int i = 0; i < n; i++)
      par[i] = i;
  }

  int find(int x)
  {
    if (par[x] != x)
      par[x] = find(par[x]);
    return par[x];
  }

  void dsu_union(int x, int y)
  {
    int leader1 = find(x);
    int leader2 = find(y);
    if (leader1 != leader2)
    {
      if (group_size[leader1] > group_size[leader2])
      {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
      }
      else
      {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
      }
    }
  }

  int numEnclaves(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();
    int totalCells = m * n;

    dsu_init(totalCells + 1);

    int escapeNode = totalCells;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          int node = i * n + j;
          if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
          {
            dsu_union(node, escapeNode);
          }

          vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
          for (auto [dx, dy] : directions)
          {
            int X = i + dx, Y = j + dy;
            if (X >= 0 && X < m && Y >= 0 && Y < n && grid[X][Y] == 1)
            {
              int neighbor = X * n + Y;
              dsu_union(node, neighbor);
            }
          }
        }
      }
    }

    int count = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          int node = i * n + j;
          if (find(node) != find(escapeNode))
          {
            count++;
          }
        }
      }
    }

    return count;
  }
};
