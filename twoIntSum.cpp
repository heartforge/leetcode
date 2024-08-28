#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      int currVal = nums[i];

      for (int j = i; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target && i != j) {
          return {i, j};
        }
      }
    }
  }
};
