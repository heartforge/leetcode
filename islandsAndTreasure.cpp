#include <algorithm>
#include <iostream>
#include <ostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  void islandsAndTreasure(vector<vector<int>> &grid) {
    cout << "Wtf" << endl;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        cout << "First" << endl;
        if (grid[i][j] > 0) {
          bfs(grid, i, j);
        }
      }
    }
  }

  void bfs(vector<vector<int>> &grid, int startR, int startC) {
    int ROWS = grid.size();
    int COLS = grid[0].size();
    vector<vector<int>> visit;
    queue<pair<int, int>> queue;
    queue.push(pair<int, int>(startR, startC));
    visit.push_back({startR, startC});

    int length = 0;

    while (queue.size() > 0) {
      int qLength = queue.size();
      for (int i = 0; i < qLength; i++) {
        pair<int, int> curr = queue.front();
        queue.pop();
        int r = curr.first;
        int c = curr.second;
        cout << "Here" << endl;
        if (grid[r][c] == 0) {
          grid[startR][startC] = length;
        }

        int neighbours[4][2] = {{r, c + 1}, {r, c - 1}, {r + 1, c}, {r - 1, c}};
        for (int j = 0; j < 4; j++) {
          int newR = neighbours[j][0];
          int newC = neighbours[j][1];

          cout << newR << endl;
          if (min(newR, newC) < 0 || newR == ROWS || newC == COLS ||
              grid[newR][newC] == -1 || visit[newR][newC] == 1) {
            continue;
          }

          visit[newR][newC] = 1;
          queue.push(pair<int, int>(newR, newC));
        }
      }
      length++;
    }
  }

  int main() {
    vector<vector<int>> in = {{2147483647, -1, 0, 2147483647},
                              {2147483647, 2147483647, 2147483647, -1},
                              {2147483647, -1, 2147483647, -1},
                              {0, -1, 2147483647, 2147483647}};
    islandsAndTreasure(in);
    return 0;
  }
};
