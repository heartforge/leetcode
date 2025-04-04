#include <vector>
class Solution {
public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    return helper(0, nums);
  }

  std::vector<std::vector<int>> helper(int i, std::vector<int> &nums) {
    if (i == nums.size()) {
      return {{}};
    }
    std::vector<std::vector<int>> resPerm;
    std::vector<std::vector<int>> perms = helper(i + 1, nums);
    for (std::vector<int> p : perms) {
      for (int j = 0; j < p.size() + 1; j++) {
        std::vector<int> pCopy(p);
        pCopy.insert(pCopy.begin() + j, nums[i]);
        resPerm.push_back(pCopy);
      }
    }
    return resPerm;
  }
};
