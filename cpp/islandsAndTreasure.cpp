#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  void islandsAndTreasure(vector<vector<int>> &grid) {
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 0) {
          bfs(grid, i, j);
        }
      }
    }
  }

  void bfs(vector<vector<int>> &grid, int i, int j) {
    int ROWS = grid.size();
    int COLS = grid[0].size();

    queue<pair<int, int>> queue;
    vector<vector<int>> visit(ROWS, vector<int>(COLS));

    queue.push(make_pair(i, j));
    visit[i][j] = 1;
    int distance = 0;

    while (queue.size() > 0) {
      int qLen = queue.size();
      for (int x = 0; x < qLen; x++) {
        pair<int, int> curCell = queue.front();
        queue.pop();
        int r = curCell.first;
        int c = curCell.second;

        if (grid[r][c] > 0) {
          grid[r][c] = min(grid[r][c], distance);
        }

        int neighbours[4][2] = {{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}};
        for (int y = 0; y < 4; y++) {
          int newR = neighbours[y][0];
          int newC = neighbours[y][1];
          if (min(newR, newC) < 0 || newR == ROWS || newC == COLS ||
              visit[newR][newC] == 1 || grid[newR][newC] <= 0) {
            continue;
          }

          queue.push(make_pair(newR, newC));
          visit[newR][newC] = 1;
        }
      }
      distance++;
    }
  }
};
