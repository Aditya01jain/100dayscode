auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();

class Solution {
    void removeIsland(short int i, short int j, vector<vector<char>> &grid)
    {
      short int m = grid.size(), n = grid[0].size();
      if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0')
        return;

      grid[i][j] = '0';
      removeIsland(i, j + 1, grid);
      removeIsland(i + 1, j, grid);
      removeIsland(i, j - 1, grid);
      removeIsland(i - 1, j, grid);
    }
public:
    short int numIslands(vector<vector<char>>& grid) {
        short int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;

        for (short int i = 0; i < m; i++)
        {
          for (short int j = 0; j < n; j++)
          {
            if (grid[i][j] == '1')
            {
              islands++;
              removeIsland(i, j, grid);
            }
          }
        }

        return islands;
    }
};