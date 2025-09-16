#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  void solve(vector<vector<char>> &board) {
    int ROWS = board.size();
    int COLS = board[0].size();
    vector<vector<int>> visit(ROWS, vector<int>(COLS, 0));

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (board[i][j] == 'O') {
          bfs(board, i, j, visit);
        }
      }
    }
  }

  vector<vector<int>> bfs(vector<vector<char>> &board, int i, int j,
                          vector<vector<int>> &visit) {
    bool surrounded = true;
    int ROWS = board.size();
    int COLS = board[0].size();
    queue<pair<int, int>> queue;
    queue.push({i, j});
    visit.push_back({i, j});
    vector<vector<int>> area;

    while (queue.size() > 0) {
      int qLen = queue.size();
      for (int x = 0; x < qLen; x++) {
        int r = queue.front().first;
        int c = queue.front().second;
        queue.pop();

        int neighbour[4][2] = {{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}};
        for (int y = 0; y < 4; y++) {
          int newR = neighbour[y][0];
          int newC = neighbour[y][1];

          if (min(newR, newC) >= 0 && newR < ROWS && newC < COLS &&
              visit[newR][newC] != 1 && board[newR][newC] == 'O') {
            queue.push({newR, newC});
            visit[newR][newC] = 1;
            area.push_back({r, c});
          }

          if (min(newR, newC) >= 0 && newR < ROWS && newC < COLS) {
            area.push_back({r, c});

            if (visit[newR][newC] != 1 && board[newR][newC] == 'O') {
              queue.push({newR, newC});
              visit[newR][newC] = 1;
            }
          } else {
            surrounded = false;
          }
        }
      }
    }
    if (!surrounded) {
      return {};
    }
    return area;
  }
};
