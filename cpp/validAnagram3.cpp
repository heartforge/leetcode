#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> m;
    for (char c : s) {
      m[c]++;
    }

    for (char x : t) {
      m[x]--;
    }

    for (auto e : m) {
      if (e.second != 0) {
        return false;
      }
    }

    return true;
  }
};
