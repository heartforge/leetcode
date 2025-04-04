#include <algorithm>
#include <vector>
class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> results;
    int lPtr = 0;
    int rPtr = nums.size() - 1;

    while (lPtr <= rPtr) {

      for (int i = lPtr + 1; i < rPtr; i++) {
        int sum = nums[lPtr] + nums[i] + nums[rPtr];

        if (sum == 0) {
          results.push_back({nums[lPtr], nums[i], nums[rPtr]});
        }
      }
      if (nums[lPtr] + nums[rPtr] <= 0) {
        int currVal = nums[lPtr];
        while (nums[lPtr] == currVal && lPtr < rPtr) {
          lPtr++;
        }

      } else if (nums[lPtr] + nums[rPtr] > 0) {
        int currVal = nums[rPtr];
        while (nums[rPtr] == currVal && lPtr >) {
          rPtr--;
        }
      }
    }
    return results;
  }
};
