// Iterate through the grid until a '1' is hit. Then run a dfs on the path of
// '1's while also deleting the '1's. This avoids detecting duplicate islands.
// Once an iteration is complete, increment the island count.
#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>
class Solution {
public:
  int numIslands(std::vector<std::vector<char>> &grid) {
    const int ROWS = grid.size();
    const int COLS = grid[0].size();
    int count = 0;

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (grid[i][j] == '1') {
          std::cout << count << std::endl;
          dfs(grid, i, j, ROWS, COLS);
          count++;
        }
      }
    }
    return count;
  }

  void dfs(std::vector<std::vector<char>> &grid, int i, int j, int ROWS,
           int COLS) {
    if (std::min(i, j) < 0 || i == ROWS || j == COLS || grid[i][j] == '0') {
      return;
    }
    grid[i][j] = '0';

    dfs(grid, i, j + 1, ROWS, COLS);
    dfs(grid, i, j - 1, ROWS, COLS);
    dfs(grid, i + 1, j, ROWS, COLS);
    dfs(grid, i - 1, j, ROWS, COLS);
  }
};
