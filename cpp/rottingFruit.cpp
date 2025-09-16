#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    int ROWS = grid.size();
    int COLS = grid[0].size();
    queue<pair<int, int>> queue;
    int fresh = 0;

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (grid[i][j] == 1) {
          fresh++;
        }
        if (grid[i][j] == 2) {
          queue.push(make_pair(i, j));
        }
      }
    }

    int time = 0;

    while (fresh > 0 && queue.size() > 0) {
      int qLen = queue.size();
      for (int x = 0; x < qLen; x++) {
        int r = queue.front().first;
        int c = queue.front().second;
        queue.pop();

        int neighbours[4][2] = {{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}};
        for (int y = 0; y < 4; y++) {
          int newR = neighbours[y][0];
          int newC = neighbours[y][1];

          if (min(newR, newC) < 0 || newR == ROWS || newC == COLS ||
              grid[newR][newC] == 0 || grid[newR][newC] == 2) {
            continue;
          }
          queue.push(make_pair(newR, newC));
          grid[newR][newC] = 2;
          fresh--;
        }
      }
      time++;
    }

    if (fresh != 0) {
      return -1;
    }
    return time;
  }
};
