#ifndef SRC_TESTS_GT_MAIN_H_
#define SRC_TESTS_GT_MAIN_H_

#define _GTEST_TIMEOUT 1

#include <gtest/gtest.h>

#include "s21_stl/array/gt_array.h"
#include "s21_stl/list/gt_list.h"
#include "s21_stl/map/gt_map.h"
#include "s21_stl/multiset/gt_multiset.h"
#include "s21_stl/queue/gt_queue.h"
#include "s21_stl/rb_tree/gt_tree.h"
#include "s21_stl/set/gt_set.h"
#include "s21_stl/stack/gt_stack.h"
#include "s21_stl/vector/gt_vector.h"

#if (_GTEST_TIMEOUT == 1)

#define TEST_TIMEOUT_BEGIN if (1) {
#define TEST_TIMEOUT_END }
#else
#define TEST_TIMEOUT_BEGIN if (0) {
#define TEST_TIMEOUT_END }
#endif

#endif /* SRC_TESTS_GT_MAIN_H_ */
