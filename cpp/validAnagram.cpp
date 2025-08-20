#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }

    unordered_map<char, int> map;

    for (int i = 0; i < s.length(); i++) {
      map[s.at(i)]++;
    }

    for (int j = 0; j < t.length(); j++) {
      map[t.at(j)]--;
    }

    for (auto entry : map) {
      if (entry.second != 0) {
        return false;
      }
    }

    return true;
  }
};
