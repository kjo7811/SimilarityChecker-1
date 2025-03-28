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

TEST_F(CheckerFixture, Test1) {
}

using namespace testing;
int main() {
  ::testing::InitGoogleMock();
  return RUN_ALL_TESTS();
}