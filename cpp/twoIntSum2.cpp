#include <vector>
class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &numbers, int target) {
    int lPtr = 0;
    int rPtr = numbers.size() - 1;

    while (lPtr <= rPtr) {
      int sum = numbers[lPtr] + numbers[rPtr];

      if (sum == target) {
        return {lPtr + 1, rPtr + 1};
      } else if (sum < target) {
        lPtr++;
      } else if (sum > target) {
        rPtr--;
      }
    }
    return {};
  }
};
