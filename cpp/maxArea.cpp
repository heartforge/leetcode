// Start at the furthest points on the vector. Keep track of the largest area
// calculated. If a pointer's neighbour is larger the other point's neighbour,
// move that pointer.
#include <algorithm>
#include <iostream>
#include <vector>
class Solution {
public:
  int maxArea(std::vector<int> &heights) {
    int largestArea = 0;
    int lPtr = 0;
    int rPtr = heights.size() - 1;

    while (lPtr < rPtr) {
      int minHeight = std::min({heights[lPtr], heights[rPtr]});
      int currArea = (rPtr - lPtr) * minHeight;
      if (currArea > largestArea) {
        largestArea = currArea;
      }
      std::cout << lPtr << "," << rPtr << std::endl;

      if (heights[lPtr] >= heights[rPtr]) {
        rPtr--;
      } else {
        lPtr++;
      }
    }
    return largestArea;
  }
};
