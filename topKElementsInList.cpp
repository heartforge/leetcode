#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::map<int, int> countMap;
        std::vector<int> result;

        for (auto& num : nums) {
            int count = countMap[num];
            countMap[num] = ++count;
        }

        for (auto& entry : countMap) {
            int currKey = entry.first;
            int currCount = entry.second;
            
            if (result.size() < k) {
                result.push_back(currKey);
            } else {
                int lowestIndex = 0;
                for (int i = 1; i < result.size(); i++) {
                    
                    if (countMap[result[i]] < countMap[result[lowestIndex]]) {
                        lowestIndex = i;
                    }
                }

                if (countMap[result[lowestIndex]] < currCount) {
                    result[lowestIndex] = currKey;
                }
            }
        
        }

        return result;
    }
};
