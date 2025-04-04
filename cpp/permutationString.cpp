#include <string>
#include <unordered_map>
class Solution {
public:
  bool checkInclusion(std::string s1, std::string s2) {
    std::unordered_map<std::string, int> stringMap1;
    std::unordered_map<std::string, int> stringMap2;
    for (char c : s1) {
      stringMap1[c]++;
    }

    int left = 0;

    for (int right = 0; right < s2.size(); right++) {
      if (stringMap1.find(s2[right]) != stringMap1.end()) {
        if (stringMap1[s2[right]] > stringMap2[s2[right]]) {
          stringMap2[s2[right]]++;
        } else {
        }
      }
    }
  }
};
