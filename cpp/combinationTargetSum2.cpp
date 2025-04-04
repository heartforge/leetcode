#include <algorithm>
#include <vector>
class Solution {
public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                                int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<int> currComb;
    std::vector<std::vector<int>> resComb;
    helper(candidates, target, 0, currComb, resComb);
    return resComb;
  }

  void helper(std::vector<int> &candidates, int target, int i,
              std::vector<int> &currComb,
              std::vector<std::vector<int>> &resComb) {
    if (target == 0) {
      resComb.push_back(currComb);
      return;
    }
    if (i >= candidates.size() || target < 0) {
      return;
    }

    currComb.push_back(candidates[i]);
    helper(candidates, target - candidates[i], i + 1, currComb, resComb);
    currComb.pop_back();

    while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
      i++;
    }
    helper(candidates, target, i + 1, currComb, resComb);
  }
};
