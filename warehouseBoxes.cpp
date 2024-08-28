#include <algorithm>
#include <iostream>
#include <ostream>
int calculateMinimumPackages(int items, int maxLargePackages,
                             int maxSmallPackages) {
  int largePackageNeeded = items / 5;
  int largePackageUsed = std::min(largePackageNeeded, maxLargePackages);
  int remaining = items - (largePackageUsed * 5);
  if (remaining > maxSmallPackages) {
    return -1;
  }

  return largePackageUsed + remaining;
}

int main() { std::cout << calculateMinimumPackages(13, 3, 5) << std::endl; }
