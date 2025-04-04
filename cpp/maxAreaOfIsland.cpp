#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;
class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int maxSize = 0;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          maxSize = max(maxSize, dfs(grid, i, j));
        }
      }
    }
    return maxSize;
  }

  int dfs(vector<vector<int>> &grid, int r, int c) {
    int ROWS = grid.size();
    int COLS = grid[0].size();

    if (min(r, c) < 0 || r == ROWS || c == COLS || grid[r][c] == 0) {
      return 0;
    }
    int area = 0;
    grid[r][c] = 0;
    area++;

    cout << area << endl;
    area += dfs(grid, r, c + 1);
    area += dfs(grid, r, c - 1);
    area += dfs(grid, r + 1, c);
    area += dfs(grid, r - 1, c);

    return area;
  }
};
