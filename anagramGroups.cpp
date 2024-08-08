#include <vector>
#include <string>
#include <map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> result;
        
        for (auto& word : strs) {
            bool anagramExists = false;
            
            for (auto& key : result) {
                
                if (isAnagram(key[0], word)) {
                    anagramExists = true;
                    key.push_back(word);
                }
            }
            if (anagramExists != true) {
                result.push_back({word});
            }
        }

        return result;
    }

    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::map<char, int> sMap;
        std::map<char, int> tMap;
        int len = s.size();

        for (int i = 0; i < len; i++) {
            char currS = s[i];
            char currT = t[i];
        
            int numS = sMap[currS];
            sMap[currS] = ++numS;

            int numT = tMap[currT];
            tMap[currT] = ++numT;
        }

        if (sMap != tMap) {
            return false;
        }
        return true;
    }
};
