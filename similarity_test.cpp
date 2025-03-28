#pragma once
#include "similarity.cpp"

#include <exception>
#include <iostream>

#include "gmock/gmock.h"
using namespace std;
class CheckerFixture : public testing::Test {
 public:
  similarityChecker checker;
};

TEST_F(CheckerFixture, CountCheckerTest1) {
  double expect = checker.charCountChecker("ASD", "DSA");
  EXPECT_EQ(expect, 60);
}

TEST_F(CheckerFixture, CountCheckerTest2) {
  double expect = checker.charCountChecker("A", "BB");
  EXPECT_EQ(expect, 0);
}
TEST_F(CheckerFixture, CountCheckerTest3) {
  double expect = checker.charCountChecker("AAABB", "BAA");
  EXPECT_EQ(expect, (1 - double(5 - 3) / 3) * 60);
}
TEST_F(CheckerFixture, CountCheckerTest4) {
  double expect = checker.charCountChecker("AA", "AAE");
  EXPECT_EQ(expect, 30);
}

TEST_F(CheckerFixture, CountCheckerTest5) {
  double expect = checker.charCountChecker("AAAAAAAAAA", "AAAAAAA");
  EXPECT_EQ(expect, (1 - double(10 - 7) / 7) * 60);
}

TEST_F(CheckerFixture, CountCheckerTest6) {
  double expect = checker.charCountChecker("AAAAA", "AA");
  EXPECT_EQ(expect, 0);
}

using namespace testing;
int main() {
  ::testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}