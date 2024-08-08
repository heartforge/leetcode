#include <vector>
#include <map>
#include <set>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        int highestCount = 0;
        std::unordered_set<int> distinctNums(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (distinctNums.find(nums[i]-1) == distinctNums.end()) {
                int currNum = nums[i];
                int currCount = 0;
                while (distinctNums.find(currNum) != distinctNums.end()) {
                    currCount++;
                    currNum++;
                }
                if (currCount > highestCount) {
                    highestCount = currCount;
                }
            }
        }

        return highestCount;
    }
};
