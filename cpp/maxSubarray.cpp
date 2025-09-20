#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int curSum = 0;
    int maxSum = nums[0];

    for (int num : nums) {
      curSum = max(curSum, 0);
      curSum += num;
      maxSum = max(maxSum, curSum);
    }
    return maxSum;
  }
};
