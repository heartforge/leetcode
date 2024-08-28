#include <algorithm>
#include <vector>
class Solution {
public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> resSubsets;
    std::vector<int> currSubset;
    helper(nums, 0, currSubset, resSubsets);
    return resSubsets;
  }

  void helper(std::vector<int> &nums, int i, std::vector<int> &currSubset,
              std::vector<std::vector<int>> &resSubsets) {
    if (i >= nums.size()) {
      resSubsets.push_back(std::vector<int>(currSubset));
      return;
    }

    currSubset.push_back(nums[i]);
    helper(nums, i + 1, currSubset, resSubsets);
    currSubset.pop_back();

    while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
      i++;
    }
    helper(nums, i + 1, currSubset, resSubsets);
  }
};
