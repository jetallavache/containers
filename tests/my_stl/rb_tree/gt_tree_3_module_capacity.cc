#include "gt_tree.h"

/*
    bool empty()
*/

TEST_F(TestTree, Empty_int) {
  my_stl::Tree<int, false> t;
  t.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});
  EXPECT_EQ(t.empty(), false);

  t.clear();
  EXPECT_EQ(t.empty(), true);
}

TEST_F(TestTree, Empty_double) {
  my_stl::Tree<double, false> t;
  t.insert({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876, 55.111111, 3.21,
            6.92929, -1, 0, -26.9876, 55.111111});
  EXPECT_EQ(t.empty(), false);

  t.clear();
  EXPECT_EQ(t.empty(), true);
}

TEST_F(TestTree, Empty_string) {
  my_stl::Tree<std::string, false> t;
  t.insert({"my_stl", "::", "::", "::", "alloc_sential_and_proxy", "()",
            "{-26.9876}", "return", "my_stl", "::", "alloc_sential_and_proxy"});
  EXPECT_EQ(t.empty(), false);

  t.clear();
  EXPECT_EQ(t.empty(), true);
}

/*
    size_type size()
*/

TEST_F(TestTree, Size_int) {
  my_stl::Tree<int, false> t;
  EXPECT_EQ((int)t.size(), 0);

  t.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});
  EXPECT_EQ((int)t.size(), 6);

  t.clear();
  EXPECT_EQ((int)t.size(), 0);
}

/*
    size_type max_size()
*/

TEST_F(TestTree, Max_size_int) {
  my_stl::Tree<int, false> t;
  t.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});

  EXPECT_EQ(t.max_size() > 1000000000, true);
}