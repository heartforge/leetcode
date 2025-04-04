#include <vector>
class Solution {
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int> &nums,
                                               int target) {
    std::vector<int> currRes;
    std::vector<std::vector<int>> res;
    helper(0, target, nums, currRes, res);
    return res;
  }

  void helper(int i, int target, std::vector<int> &nums,
              std::vector<int> &currRes, std::vector<std::vector<int>> &res) {
    if (target == 0) {
      res.push_back(std::vector<int>(currRes));
      return;
    }
    if (i > nums.size()) {
      return;
    }

    currRes.push_back(nums[i]);
    helper(i + 1, target - nums[i], nums, currRes, res);
    currRes.pop_back();
    helper(i + 1, target, nums, currRes, res);
  }
};
