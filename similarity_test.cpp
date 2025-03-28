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

TEST_F(CheckerFixture, getScoreTest1) {
  double expect = checker.getScore("ASD", "DSA");
  EXPECT_EQ(expect, 100);
}

TEST_F(CheckerFixture, getScoreTest2) {
  double expect = checker.getScore("A", "BB");
  EXPECT_EQ(expect, 0);
}
TEST_F(CheckerFixture, getScoreTest3) {
  double expect = checker.getScore("AAABB", "BAA");
  EXPECT_EQ(expect, 60);
}
TEST_F(CheckerFixture, getScoreTest4) {
  double expect = checker.getScore("AA", "AAE");
  EXPECT_EQ(expect, 50);
}

TEST_F(CheckerFixture, getScoreTest5) {
  double expect = checker.getScore("AAAAAAAAAA", "AAAAAAA");
  EXPECT_EQ(expect, (1 - double(10 - 7) / 7) * 60 + 40);
}

TEST_F(CheckerFixture, getScoreTest6) {
  double expect = checker.getScore("AAAAA", "AA");
  EXPECT_EQ(expect, 40);
}

TEST_F(CheckerFixture, CountCheckerThrow) {
  EXPECT_THROW(checker.getScore("", "ASD"), std::invalid_argument);
}

TEST_F(CheckerFixture, SameCheckerThrow) {
  EXPECT_THROW(checker.getScore("AS", "ASDa"), std::invalid_argument);
}

using namespace testing;
int main() {
  ::testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}