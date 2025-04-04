#include <vector>
class Solution {
public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    std::vector<int> currSet;
    std::vector<std::vector<int>> subsets;
    helper(0, nums, currSet, subsets);
    return subsets;
  }

  void helper(int i, std::vector<int> &nums, std::vector<int> &currSet,
              std::vector<std::vector<int>> &subsets) {
    if (i >= nums.size()) {
      subsets.push_back(std::vector<int>(currSet));
      return;
    }

    currSet.push_back(nums[i]);
    helper(i + 1, nums, currSet, subsets);
    currSet.pop_back();

    helper(i + 1, nums, currSet, subsets);
  }
};
