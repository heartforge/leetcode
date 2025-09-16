#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int ROWS = heights.size();
    int COLS = heights[0].size();

    vector<vector<int>> res;

    vector<vector<int>> pac(ROWS, vector<int>(COLS, 0));
    vector<vector<int>> atl(ROWS, vector<int>(COLS, 0));

    for (int r = 0; r < ROWS; r++) {
      dfs(heights, r, 0, pac);
      dfs(heights, r, COLS - 1, atl);
    }

    for (int c = 0; c < COLS; c++) {
      dfs(heights, 0, c, pac);
      dfs(heights, ROWS - 1, c, atl);
    }

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (pac[i][j] && atl[i][j]) {
          res.push_back({i, j});
        }
      }
    }

    return res;
  }

  void dfs(vector<vector<int>> &heights, int r, int c,
           vector<vector<int>> &visit) {
    int ROWS = heights.size();
    int COLS = heights[0].size();

    int neighbours[4][2] = {{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}};

    visit[r][c] = 1;
    for (int i = 0; i < 4; i++) {
      int newR = neighbours[i][0];
      int newC = neighbours[i][1];

      if (min(newR, newC) >= 0 && newR < ROWS && newC < COLS &&
          heights[newR][newC] >= heights[r][c] && visit[newR][newC] != 1) {
        dfs(heights, newR, newC, visit);
      }
    }

    return;
  }
};
