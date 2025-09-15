#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int maxArea = 0;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          // Get length using BFS.
          int curLen = bfs(grid, i, j);
          // Compare to current max.
          maxArea = max(maxArea, curLen);
        }
      }
    }
    return maxArea;
  }

  int bfs(vector<vector<int>> &grid, int i, int j) {
    int ROWS = grid.size();
    int COLS = grid[0].size();
    queue<pair<int, int>> queue;
    if (grid[i][j] == 1) {
      queue.push(make_pair(i, j));
    }
    int length = 1;

    while (queue.size() > 0) {
      int qLen = queue.size();
      for (i = 0; i < qLen; i++) {
        pair<int, int> curr = queue.front();
        queue.pop();
        int r = curr.first;
        int c = curr.second;
        grid[r][c] = 0;

        int neighbours[4][2] = {{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}};
        for (j = 0; j < 4; j++) {
          int newR = neighbours[j][0];
          int newC = neighbours[j][1];
          if (min(newR, newC) < 0 || newR == ROWS || newC == COLS ||
              grid[newR][newC] == 0) {
            continue;
          }
          queue.push(make_pair(newR, newC));
          grid[newR][newC] = 0;
          length++;
        }
      }
    }
    return length;
  }
};
