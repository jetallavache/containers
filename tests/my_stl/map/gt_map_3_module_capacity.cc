#include "gt_map.h"

/*
    bool empty()
*/

TEST_F(TestMap, Empty_int) {
  my_stl::Map<int, int> m;
  m.insert(1, 7);
  m.insert(2, 4);
  m.insert(3, -1);
  m.insert(4, 8);
  EXPECT_EQ(m.empty(), false);

  m.clear();
  EXPECT_EQ(m.empty(), true);
}

TEST_F(TestMap, Empty_double) {
  my_stl::Map<int, double> m;
  m.insert(1, 709876.00987);
  m.insert(2, 4543.9876);
  m.insert(3, -1.9876);
  m.insert(4, -8765432.124);
  EXPECT_EQ(m.empty(), false);

  m.clear();
  EXPECT_EQ(m.empty(), true);
}

TEST_F(TestMap, Empty_string) {
  my_stl::Map<int, std::string> m;
  m.insert(1, "alloc_sential");
  m.insert(10, "alloc_sential_and");
  m.insert(100, "alloc_sential_and_proxy");
  EXPECT_EQ(m.empty(), false);

  m.clear();
  EXPECT_EQ(m.empty(), true);
}

/*
    size_type size()
*/

TEST_F(TestMap, Size_int) {
  my_stl::Map<int, int> m;
  EXPECT_EQ((int)m.size(), 0);

  m.insert(1, 7);
  m.insert(2, 4);
  m.insert(3, -1);
  m.insert(4, 8);
  EXPECT_EQ((int)m.size(), 4);

  m.clear();
  EXPECT_EQ((int)m.size(), 0);
}

/*
    size_type max_size()
*/

TEST_F(TestMap, Max_size_int) {
  my_stl::Map<int, int> m;
  m.insert(1, 7);
  m.insert(2, 4);
  m.insert(3, -1);
  m.insert(4, 8);

  EXPECT_EQ(m.max_size() > 1000000000, true);
}