#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    vector<int> memo(nums.size(), -1);
    return dfs(nums, memo, 0);
  }

  int dfs(vector<int> &nums, vector<int> &memo, int i) {
    if (i >= nums.size()) {
      return 0;
    }
    if (memo[i] != -1) {
      return memo[i];
    }

    int take = nums[i] + dfs(nums, memo, i + 2);
    int skip = dfs(nums, memo, i + 1);
    memo[i] = max(take, skip);

    return memo[i];
  }
};
