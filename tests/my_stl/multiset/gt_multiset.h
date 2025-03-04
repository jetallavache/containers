#ifndef SRC_TESTS_MY_STL_MULTISET_GT_MULTISET_H_
#define SRC_TESTS_MY_STL_MULTISET_GT_MULTISET_H_

#include <gtest/gtest.h>

#include <set>
#include <vector>

#include "../../../include/containers.h"

#define MULTISET_EXPECT_EQ(multiset1, multiset2)   \
  {                                                \
    auto it1 = multiset1.begin();                  \
    auto it2 = multiset2.begin();                  \
    for (; it1 != multiset1.end(); ++it1, ++it2) { \
      EXPECT_EQ(*it1, *it2);                       \
    }                                              \
    EXPECT_EQ(multiset1.size(), multiset2.size()); \
  }

class TestMultiset : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
};

#endif  // SRC_TESTS_MY_STL_MULTISET_GT_MULTISET_H_