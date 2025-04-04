#include <iostream>
#include <map>
#include <set>
#include <vector>

class Solution {
public:
  int longestConsecutive(std::vector<int> &nums) {
    int finalKey;
    int finalCount = 0;
    std::map<int, std::set<int>> resMap;

    for (int i = 0; i < nums.size(); i++) {
      std::set<int> consecSet{nums[i]};
      int currCount = 1;
      int below = nums[i] - 1;
      int above = nums[i] + 1;

      if (resMap.find(below) != resMap.end()) {
        std::set<int> belowSet = resMap[below];
        currCount += belowSet.size();
        consecSet.insert(belowSet.begin(), belowSet.end());
      }
      if (resMap.find(above) != resMap.end()) {
        std::set<int> aboveSet = resMap[above];
        currCount += aboveSet.size();
        consecSet.insert(aboveSet.begin(), aboveSet.end());
      }

      if (currCount > finalCount) {
        finalCount = currCount;
      }
      resMap[nums[i]] = consecSet;
    }
    return finalCount;
  }

  // 2 | {2}
  // 20 | {20}
  // 4 | {4}
  // 10 | {10}
  // 3 | {2,3,4}
  // 4 | {2,3,4}
  // 5 | {2,3,4,5}

  // create map of each element
  // track index that has highest count
  // for each element, see if the value +-1 exists in the map
  // if true, combine the elements
};
