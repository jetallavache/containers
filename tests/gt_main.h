#ifndef SRC_TESTS_GT_MAIN_H_
#define SRC_TESTS_GT_MAIN_H_

#define _GTEST_TIMEOUT 1

#include <gtest/gtest.h>

#include "my_stl/map/gt_map.h"
#include "my_stl/multiset/gt_multiset.h"
#include "my_stl/rb_tree/gt_tree.h"
#include "my_stl/set/gt_set.h"

#if (_GTEST_TIMEOUT == 1)

#define TEST_TIMEOUT_BEGIN if (1) {
#define TEST_TIMEOUT_END }
#else
#define TEST_TIMEOUT_BEGIN if (0) {
#define TEST_TIMEOUT_END }
#endif

#endif /* SRC_TESTS_GT_MAIN_H_ */
