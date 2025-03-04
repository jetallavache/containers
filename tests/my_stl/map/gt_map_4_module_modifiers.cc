#include "gt_map.h"

/*
  void clear()
*/

TEST_F(TestMap, Clear_int) {
  my_stl::Map<int, int> m;
  m.insert(1, 7);
  m.insert(2, 4);
  m.insert(3, -1);
  m.insert(4, 8);
  EXPECT_EQ(m.empty(), false);

  m.clear();
  EXPECT_EQ(m.empty(), true);
}

TEST_F(TestMap, Clear_double) {
  my_stl::Map<int, double> m;
  m.insert(1, 709876.00987);
  m.insert(2, 4543.9876);
  m.insert(3, -1.9876);
  m.insert(4, -8765432.124);
  EXPECT_EQ(m.empty(), false);

  m.clear();
  EXPECT_EQ(m.empty(), true);
}

TEST_F(TestMap, Clear_string) {
  my_stl::Map<int, std::string> m;
  m.insert(1, "alloc_sential");
  m.insert(10, "alloc_sential_and");
  m.insert(100, "alloc_sential_and_proxy");
  EXPECT_EQ(m.empty(), false);

  m.clear();
  EXPECT_EQ(m.empty(), true);
}

/*
  void insert(std::initializer_list<value_type> ilist)
*/

TEST_F(TestMap, Insert_initializer_list_int) {
  auto ls1 = my_stl::make_mypair(1, 600);
  auto ls2 = my_stl::make_mypair(2, 700);
  auto ls3 = my_stl::make_mypair(3, 800);

  my_stl::Map<int, int> m1;
  m1.insert({ls1, ls2, ls3});

  std::map<int, int> m2({ls1, ls2, ls3});

  MAP_EXPECT_EQ(m1, m2);

  EXPECT_EQ(3, (int)m1.size());
}

/*
  std::pair<iterator, bool> insert_or_assign(const key_type& key,
                                             const mapped_type& obj)
*/

TEST_F(TestMap, Insert_or_assign_value_int) {
  my_stl::Map<int, int> m;
  m.insert_or_assign(1, 7);
  m.insert_or_assign(1, 9);
  m.insert_or_assign(2, 4);
  m.insert_or_assign(2, 12);
  m.insert_or_assign(3, -1);
  m.insert_or_assign(1, 70);
  m.insert_or_assign(4, 8);
  m.insert_or_assign(2, 34);
  m.insert_or_assign(3, -1);
  m.insert_or_assign(3, -100);

  auto it = m.begin();
  EXPECT_EQ((*it).first, 1);
  EXPECT_EQ((*it++).second, 70);
  EXPECT_EQ((*it).first, 2);
  EXPECT_EQ((*it++).second, 34);
  EXPECT_EQ((*it).first, 3);
  EXPECT_EQ((*it++).second, -100);
  EXPECT_EQ((*it).first, 4);
  EXPECT_EQ((*it++).second, 8);

  EXPECT_EQ(4, (int)m.size());
}

/*
  std::pair<iterator, bool> insert(const_value_reference value)
*/

TEST_F(TestMap, Insert_value_int) {
  my_stl::Map<int, int> m;
  m.insert(1, 7);
  m.insert(1, 7);
  m.insert(2, 4);
  m.insert(2, 4);
  m.insert(3, -1);
  m.insert(1, 7);
  m.insert(4, 8);
  m.insert(2, 4);

  auto it = m.begin();
  EXPECT_EQ((*it).first, 1);
  EXPECT_EQ((*it++).second, 7);
  EXPECT_EQ((*it).first, 2);
  EXPECT_EQ((*it++).second, 4);
  EXPECT_EQ((*it).first, 3);
  EXPECT_EQ((*it++).second, -1);
  EXPECT_EQ((*it).first, 4);
  EXPECT_EQ((*it++).second, 8);

  EXPECT_EQ(4, (int)m.size());
}

/*
  size_type erase(const_iterator pos)
*/

TEST_F(TestMap, Erase_int) {
  my_stl::Map<int, int> m;
  m.insert(1, 7);
  m.insert(2, 4);
  m.insert(3, -1);
  m.insert(4, 8);

  auto it = m.find(my_stl::make_mypair(1, 7));
  EXPECT_EQ(((*it).first == 1), true);
  m.erase(it);
  it = m.find(my_stl::make_mypair(1, 7));
  EXPECT_EQ((it == m.end()), true);

  it = m.find(my_stl::make_mypair(4, 8));
  EXPECT_EQ(((*it).first == 4), true);
  m.erase(it);
  it = m.find(my_stl::make_mypair(4, 8));
  EXPECT_EQ((it == m.end()), true);

  EXPECT_EQ((int)m.size(), 2);
}

/*
  void swap(set& other)
*/

TEST_F(TestMap, Swap_int) {
  my_stl::Map<int, int> expect_left;
  expect_left.insert(1, 7);
  expect_left.insert(2, 4);
  expect_left.insert(3, -1);
  expect_left.insert(4, 8);

  my_stl::Map<int, int> expect_right;
  expect_right.insert(5, 55);
  expect_right.insert(6, 66);

  my_stl::Map<int, int> m_left;
  m_left.insert(5, 55);
  m_left.insert(6, 66);

  my_stl::Map<int, int> m_right;
  m_right.insert(1, 7);
  m_right.insert(2, 4);
  m_right.insert(3, -1);
  m_right.insert(4, 8);

  m_left.swap(m_right);

  MAP_EXPECT_EQ(expect_left, m_left);
  MAP_EXPECT_EQ(expect_right, m_right);
}

/*
  void merge(set& other);
*/

TEST_F(TestMap, Merge_int) {
  my_stl::Map<int, int> m_union;
  m_union.insert(1, 7);
  m_union.insert(2, 4);
  m_union.insert(3, -1);
  m_union.insert(4, 8);
  m_union.insert(5, 55);
  m_union.insert(6, 66);

  my_stl::Map<int, int> m_left;
  m_left.insert(1, 7);
  m_left.insert(2, 4);
  m_left.insert(3, -1);
  m_left.insert(4, 8);

  my_stl::Map<int, int> m_right;
  m_right.insert(5, 55);
  m_right.insert(6, 66);

  m_left.merge(m_right);
  MAP_EXPECT_EQ(m_union, m_left);
}
