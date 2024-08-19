// Contain set of seen chars. The left bound is beginning of the substring.
// The right bound is the end of it. For loop is used to iterate through the
// string. Whenever the current char is contained in the set, increment left
// bound until this clause is no longer true.
#include <string>
#include <unordered_set>
class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> seenChars;
    int leftBound = 0;
    int longestSubStr = 0;
    for (int rightBound = 0; rightBound < s.size(); rightBound++) {
      while (seenChars.find(s[rightBound]) != seenChars.end()) {
        seenChars.erase(s[leftBound]);
        leftBound++;
      }
      seenChars.insert(s[rightBound]);
      longestSubStr = std::max(longestSubStr, rightBound - leftBound + 1);
    }
    return longestSubStr;
  }
};
