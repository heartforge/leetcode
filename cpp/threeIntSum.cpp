#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    // int l = 0;
    // int r = nums.size() - 1;
    int target = 0;
    std::vector<std::vector<int>> result;

    for (int num : nums) {
      int l = 0;
      int r = nums.size() - 1;
      while (l < r) {
        if (num + nums[l] + nums[r] > 0) {
          r--;
        } else if (num + nums[l] + nums[r] < 0) {
          l++;
        } else {
          result.push_back({num, nums[l], nums[r]});
        }
      }
    }

    // while (l < r) {
    //     if (num + nums[l] + nums[r] > 0) {
    //         r--;
    //     } else if (num + nums[l] + nums[r] < 0) {
    //         l++;
    //     } else {
    //         result.push_back({num, nums[l], nums[r]});
    //     }
    // }
    return result;
  }
};
