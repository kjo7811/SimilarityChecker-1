#include <iostream>
#include <stdexcept>

struct similarityChecker {
 public:
  double getScore(const std::string& a, const std::string& b) {
    return getCountScore(a, b) + getSameScore(a, b);
  }

 private:
  double getCountScore(const std::string& a, const std::string& b) {
    int aLen = a.length();
    int bLen = b.length();
    if (aLen == 0 || bLen == 0) throw std::invalid_argument("string is empty");

    if (aLen < bLen) {
      int tmp = aLen;
      aLen = bLen;
      bLen = tmp;
    }

    return calculateCountScore(aLen, bLen);
  }

  double getSameScore(const std::string& a, const std::string& b) {
    bool isUsedAlpaA[26] = {
        0,
    };
    bool isUsedAlpaB[26] = {
        0,
    };

    updateIsUsedAlpa(a, isUsedAlpaA);
    updateIsUsedAlpa(b, isUsedAlpaB);

    return calculateSameScore(isUsedAlpaA, isUsedAlpaB);
  }

  double calculateCountScore(int aLen, int bLen) {
    if (aLen >= bLen * 2) return 0;
    return (1 - ((double(aLen) - double(bLen)) / bLen)) * 60;
  }

  void updateIsUsedAlpa(const std::string& a, bool isUsedAlpaA[26]) {
    for (char ch : a) {
      if (ch < 'A' || ch > 'Z') throw std::invalid_argument("Not a upper case");
      isUsedAlpaA[ch - 'A'] = true;
    }
  }

  double calculateSameScore(bool isUsedAlpaA[26], bool isUsedAlpaB[26]) {
    int sameCnt = 0;
    int totalCnt = 0;
    for (int i = 0; i < 26; i++) {
      if (isUsedAlpaA[i] || isUsedAlpaB[i]) totalCnt++;
      if (isUsedAlpaA[i] && isUsedAlpaB[i]) sameCnt++;
    }
    return (sameCnt * 40) / double(totalCnt);
  }
};
