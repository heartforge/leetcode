class Solution {
public:
  int climbStairs(int n) {

    if (n < 0) {
      return 0;
    }
    if (n == 0) {
      return 1;
    }

    int count = 0;
    count += climbStairs(n - 1);
    count += climbStairs(n - 2);

    return count;
  }
};
