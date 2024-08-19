#include <vector>
class Solution {
public:
  int search(std::vector<int> &nums, int target) {
    if (nums.size() == 0) {
      return -1;
    }

    int lowerBound = 0;
    int upperBound = nums.size() - 1;

    while (lowerBound <= upperBound) {
      int middle = lowerBound + ((upperBound - lowerBound) / 2);
      if (nums[middle] < target) {
        lowerBound = middle + 1;
      } else if (nums[middle] > target) {
        upperBound = middle - 1;
      } else {
        return middle;
      }
    }

    return -1;
  }
};
