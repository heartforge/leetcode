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
    vector<vector<int>> invalid(ROWS, vector<int>(COLS, 0));
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        bool top = i == 0;
        bool bot = i == ROWS - 1;
        bool left = j == 0;
        bool right = j == COLS - 1;

        if (top || bot || left || right) {
          if (board[i][j] == 'O' && invalid[i][j] == 0) {
            bfs(board, i, j, invalid);
          }
        }
      }
    }

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (invalid[i][j] == 0) {
          board[i][j] = 'X';
        }
      }
    }
  }

  void bfs(vector<vector<char>> &board, int i, int j,
           vector<vector<int>> &visit) {
    int ROWS = board.size();
    int COLS = board[0].size();
    queue<pair<int, int>> queue;
    visit[i][j] = 1;
    queue.push({i, j});

    while (queue.size() > 0) {
      int qLen = queue.size();
      for (int x = 0; x < qLen; x++) {
        pair<int, int> curr = queue.front();
        queue.pop();
        int r = curr.first;
        int c = curr.second;

        int neighbour[4][2] = {{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}};
        for (int y = 0; y < 4; y++) {
          int newR = neighbour[y][0];
          int newC = neighbour[y][1];

          if (min(newR, newC) > 0 && newR < ROWS && newC < COLS &&
              board[newR][newC] == 'O' && visit[newR][newC] == 0) {
            queue.push({newR, newC});
            visit[newR][newC] = 1;
          }
        }
      }
    }
  }
};
