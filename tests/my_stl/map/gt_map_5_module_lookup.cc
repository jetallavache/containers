#include "gt_map.h"

/*
  iterator find(const_value_reference value)
*/

TEST_F(TestMap, Find_return_iter_int) {
  my_stl::Map<int, int> m;
  m.insert(1, 7);
  m.insert(2, 4);
  m.insert(3, -1);
  m.insert(4, 8);

  auto it = m.find(my_stl::make_mypair(1, 7));
  EXPECT_EQ(((*it).first == 1), true);
  EXPECT_EQ(((*it).second == 7), true);

  it = m.find(my_stl::make_mypair(3, -1));
  EXPECT_EQ(((*it).first == 3), true);
  EXPECT_EQ(((*it).second == -1), true);

  /* Not found */
  it = m.find(my_stl::make_mypair(0, 999));
  EXPECT_EQ((it == m.end()), true);
  EXPECT_EQ((it == m.end()), true);
}

/*
  const_iterator find(const_value_reference value) const
*/

/*
  bool contains(const Key& key)
*/

TEST_F(TestMap, Contains_int) {
  my_stl::Map<int, int> m;
  m.insert(1, 7);
  m.insert(2, 4);
  m.insert(3, -1);
  m.insert(4, 8);

  EXPECT_EQ(m.contains(1), true);
  EXPECT_EQ(m.contains(2), true);
  EXPECT_EQ(m.contains(3), true);
  EXPECT_EQ(m.contains(4), true);

  /* Not found */
  EXPECT_EQ(m.contains(5), false);
  EXPECT_EQ(m.contains(6), false);
}
