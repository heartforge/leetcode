#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

class Friend {
public:
  std::vector<Friend *> friends;

  Friend(std::string email) { this->email = email; }

  void addFriendship(Friend *target) {
    friends.push_back(target);
    target->friends.push_back(this);
  }

  bool canBeConnected(Friend *target) {
    if (this == target) { // Assuming this can be friends with itself
      return true;
    }
    std::unordered_set<Friend *> visited;
    std::stack<Friend *> toVisit;
    toVisit.push(this);

    while (!toVisit.empty()) {
      Friend *curr = toVisit.top();
      toVisit.pop();

      if (curr == target) {
        return true;
      }

      if (visited.find(curr) == visited.end()) {
        visited.insert(curr);

        for (int i = 0; i < curr->friends.size(); i++) {
          if (visited.find(curr->friends[i]) == visited.end()) {
            toVisit.push(curr->friends[i]);
          }
        }
      }
    }

    return false;
  }

private:
  std::string email;
};

#ifndef RunTests
int main() {
  Friend a("A");
  Friend b("B");
  Friend c("C");

  a.addFriendship(&b);
  b.addFriendship(&c);

  std::cout << a.canBeConnected(&c);
}
#endif
