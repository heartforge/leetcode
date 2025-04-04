// Interate through the vector. For each element, find the largest left and
// right walls. Take the min of those walls and subtract it by the value of the
// current element. Add all these together to calculate trapped rain water.
#include <vector>
class Solution {
public:
  int trap(std::vector<int> &height) {
    int trappedWater = 0;
    for (int i = 0; i < height.size(); i++) {
      int lPtr = i - 1;
      int rPtr = i + 1;
      int largestLeft = 0;
      int largestRight = 0;

      while (lPtr >= 0) {
        if (height[lPtr] > largestLeft) {
          largestLeft = height[lPtr];
        }
        lPtr--;
      }
      while (rPtr <= height.size() - 1) {
        if (height[rPtr] > largestRight) {
          largestRight = height[rPtr];
        }
        rPtr++;
      }

      int smallestWall = std::min({largestLeft, largestRight});
      if (smallestWall > height[i]) {
        trappedWater += (smallestWall - height[i]);
      }
    }
    return trappedWater;
  }
};
