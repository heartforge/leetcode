#include <vector>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int len = nums.size();
    int res = nums[0];

    int q = 0;

    for (int i = 1; i < len + 1; i++) {
      q = q ^ i;
    }

    for (int i = 1; i < len; i++) {
      res = res ^ nums[i];
    }

    return res ^ q;
  }
};
