#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }
    vector<vector<int>> memo(nums.size(), vector<int>(2, -1));
    int flagged = dfs(nums, 0, true, memo);
    int unflagged = dfs(nums, 1, false, memo);
    return max(flagged, unflagged);
  }

  int dfs(vector<int> &nums, int i, int flag, vector<vector<int>> &memo) {
    if (i >= nums.size() || (i == nums.size() - 1 && flag)) {
      return 0;
    }
    if (memo[i][flag] != -1) {
      return memo[i][flag];
    }

    int skip = dfs(nums, i + 1, flag, memo);
    int take = nums[i] + dfs(nums, i + 2, flag, memo);

    memo[i][flag] = max(skip, take);

    return memo[i][flag];
  }
};
