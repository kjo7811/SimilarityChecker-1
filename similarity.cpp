#include <iostream>
#include <stdexcept>

struct similarityChecker {
 public:
  double charCountChecker(const std::string& a, const std::string& b) {
    int aLen = a.length();
    int bLen = b.length();
    if (aLen < bLen) {
      int tmp = aLen;
      aLen = bLen;
      bLen = tmp;
    }
    if (aLen >= bLen * 2) return 0;
    return (1 - ((double(aLen) - double(bLen)) / bLen)) * 60;
  }
};
