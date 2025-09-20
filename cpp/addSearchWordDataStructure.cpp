#include <string>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
  unordered_map<char, TrieNode *> children_;
  bool word_ = false;
};

class WordDictionary {
public:
  TrieNode root_;

  WordDictionary() {}

  void addWord(string word) {
    TrieNode *curr = &root_;
    for (char c : word) {
      if (curr->children_.count(c) == 0) {
        curr->children_[c] = new TrieNode();
      }
      curr = curr->children_[c];
    }
    curr->word_ = true;
  }

  bool search(string word) {
    TrieNode *curr = &root_;
    for (char c : word) {
      if (curr->children_.count(c) == 0) {
        return false;
      }
      curr = curr->children_[c];
    }
    return curr->word_;
  }
};
