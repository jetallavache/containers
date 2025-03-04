#ifndef SRC_TESTS_MY_STL_SET_GT_SET_H_
#define SRC_TESTS_MY_STL_SET_GT_SET_H_

#include <gtest/gtest.h>

#include <set>

#include "../../../include/containers.h"

#define SET_EXPECT_EQ(set1, set2)             \
  {                                           \
    auto it1 = set1.begin();                  \
    auto it2 = set2.begin();                  \
    for (; it1 != set1.end(); ++it1, ++it2) { \
      EXPECT_EQ(*it1, *it2);                  \
    }                                         \
    EXPECT_EQ(set1.size(), set2.size());      \
  }

class TestSet : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
};

#endif  // SRC_TESTS_MY_STL_SET_GT_SET_H_
