#include <unordered_set>
#include <vector>
class Solution {
public:
  bool hasDuplicate(std::vector<int> &nums) {
    std::unordered_set<int> seenVals;
    for (int i = 0; i < nums.size(); i++) {
      if (seenVals.find(nums[i]) != seenVals.end()) {
        return true;
      } else {
        seenVals.insert(nums[i]);
      }
    }
    return false;
  }
};
