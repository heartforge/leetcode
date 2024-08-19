// Get distinct set of chars. Iterate through the string. For each element,
// check for the longest substring that matches the condition. Do this
// for each distinct char.
#include <algorithm>
#include <string>
#include <unordered_set>
class Solution {
public:
  int characterReplacement(std::string s, int k) {
    std::unordered_set<char> distinctChar;
    int longestSub = 0;
    for (char c : s) {
      distinctChar.insert(c);
    }

    for (int left = 0; left < s.size(); left++) {
      for (char currChar : distinctChar) {
        int right = left;
        int deltaCount = 0;
        while (right < s.size() && (s[right] == currChar || deltaCount < k)) {
          if (s[right] != currChar) {
            deltaCount++;
          }
          right++;
        }

        longestSub = std::max(longestSub, right - left);
      }
    }
    return longestSub;
  }
};
