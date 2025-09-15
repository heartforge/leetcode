#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          count++;
          dfs(grid, i, j);
        }
      }
    }
    return count;
  }

  void dfs(vector<vector<char>> &grid, int r, int c) {
    int ROWS = grid.size();
    int COLS = grid[0].size();

    if (min(r, c) < 0 || r == ROWS || c == COLS || grid[r][c] == '0') {
      return;
    }

    grid[r][c] = '0';

    dfs(grid, r + 1, c);
    dfs(grid, r - 1, c);
    dfs(grid, r, c + 1);
    dfs(grid, r, c - 1);
    return;
  }
};
