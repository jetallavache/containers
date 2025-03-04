#include "gt_multiset.h"

/*
  size_type count(const Key& key)
*/

TEST_F(TestMultiset, Count_int) {
  my_stl::Multiset<int> s({1, 2, 2, 3, 3, 3});
  ASSERT_EQ(s.count(1), 1);
  ASSERT_EQ(s.count(2), 2);
  ASSERT_EQ(s.count(3), 3);
  ASSERT_EQ(s.count(4), 0);
}

/*
  iterator find(const_value_reference value)
*/

TEST_F(TestMultiset, Find_return_iter_int) {
  my_stl::Multiset<int> s;
  s.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});

  my_stl::Multiset<int>::iterator it = s.find(-26);
  EXPECT_EQ(*it, -26);
  it = s.find(0);
  EXPECT_EQ(*it, 0);
  it = s.find(55);
  EXPECT_EQ(*it, 55);

  /* Not found */
  it = s.find(10000);
  EXPECT_EQ(it == s.end(), true);
  it = s.find(-2123);
  EXPECT_EQ(it == s.end(), true);
}

TEST_F(TestMultiset, Find_return_iter_double) {
  my_stl::Multiset<double> s;
  s.insert({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876, 55.111111, 3.21,
            6.92929, -1, 0, -26.9876, 55.111111});

  my_stl::Multiset<double>::iterator it = s.find(6.92929);
  EXPECT_EQ(*it, 6.92929);
  it = s.find(0);
  EXPECT_EQ(*it, 0);
  it = s.find(55.111111);
  EXPECT_EQ(*it, 55.111111);

  /* Not found */
  it = s.find(55.1111);
  EXPECT_EQ(it == s.end(), true);
  it = s.find(-12.023921);
  EXPECT_EQ(it == s.end(), true);
}

TEST_F(TestMultiset, Find_return_iter_string) {
  my_stl::Multiset<std::string> s;
  s.insert({"my_stl", "::", "::", "::", "alloc_sential_and_proxy", "()",
            "{-26.9876}", "return", "my_stl", "::", "alloc_sential_and_proxy"});

  my_stl::Multiset<std::string>::iterator it = s.find("::");
  EXPECT_EQ(*it, "::");
  it = s.find("return");
  EXPECT_EQ(*it, "return");
  it = s.find("alloc_sential_and_proxy");
  EXPECT_EQ(*it, "alloc_sential_and_proxy");

  /* Not found */
  it = s.find("alloc_sential_and");
  EXPECT_EQ(it == s.end(), true);
  it = s.find("");
  EXPECT_EQ(it == s.end(), true);
}

/*
  const_iterator find(const_value_reference value) const
*/

TEST_F(TestMultiset, Find_return_const_iter_int) {
  my_stl::Multiset<int> s;
  s.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});

  my_stl::Multiset<int>::const_iterator it = s.find(-26);
  EXPECT_EQ(*it, -26);
  it = s.find(0);
  EXPECT_EQ(*it, 0);
  it = s.find(55);
  EXPECT_EQ(*it, 55);

  /* Not found */
  it = s.find(10000);
  EXPECT_EQ(it == s.end(), true);
  it = s.find(-2123);
  EXPECT_EQ(it == s.end(), true);
}

TEST_F(TestMultiset, Find_return_const_iter_double) {
  my_stl::Multiset<double> s;
  s.insert({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876, 55.111111, 3.21,
            6.92929, -1, 0, -26.9876, 55.111111});

  my_stl::Multiset<double>::const_iterator it = s.find(6.92929);
  EXPECT_EQ(*it, 6.92929);
  it = s.find(0);
  EXPECT_EQ(*it, 0);
  it = s.find(55.111111);
  EXPECT_EQ(*it, 55.111111);

  /* Not found */
  it = s.find(55.1111);
  EXPECT_EQ(it == s.end(), true);
  it = s.find(-12.023921);
  EXPECT_EQ(it == s.end(), true);
}

TEST_F(TestMultiset, Find_returnconst__iter_string) {
  my_stl::Multiset<std::string> s;
  s.insert({"my_stl", "::", "::", "::", "alloc_sential_and_proxy", "()",
            "{-26.9876}", "return", "my_stl", "::", "alloc_sential_and_proxy"});

  my_stl::Multiset<std::string>::const_iterator it = s.find("::");
  EXPECT_EQ(*it, "::");
  it = s.find("return");
  EXPECT_EQ(*it, "return");
  it = s.find("alloc_sential_and_proxy");
  EXPECT_EQ(*it, "alloc_sential_and_proxy");

  /* Not found */
  it = s.find("alloc_sential_and");
  EXPECT_EQ(it == s.end(), true);
  it = s.find("");
  EXPECT_EQ(it == s.end(), true);
}

/*
  bool contains(const Key& key)
*/

TEST_F(TestMultiset, Contains_int) {
  my_stl::Multiset<int> s;
  s.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});

  EXPECT_EQ(s.contains(6), true);
  EXPECT_EQ(s.contains(-1), true);
  EXPECT_EQ(s.contains(55), true);
  EXPECT_EQ(s.contains(0), true);

  /* Not found */
  EXPECT_EQ(s.contains(60), false);
  EXPECT_EQ(s.contains(-100), false);
}

TEST_F(TestMultiset, Contains_double) {
  my_stl::Multiset<double> s;
  s.insert({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876, 55.111111, 3.21,
            6.92929, -1, 0, -26.9876, 55.111111});

  EXPECT_EQ(s.contains(6.92929), true);
  EXPECT_EQ(s.contains(-1), true);
  EXPECT_EQ(s.contains(3.21), true);
  EXPECT_EQ(s.contains(55.111111), true);

  /* Not found */
  EXPECT_EQ(s.contains(0.0001), false);
  EXPECT_EQ(s.contains(10000.1), false);
}

TEST_F(TestMultiset, Contains_string) {
  my_stl::Multiset<std::string> s;
  s.insert({"my_stl", "::", "::", "::", "alloc_sential_and_proxy", "()",
            "{-26.9876}", "return", "my_stl", "::", "alloc_sential_and_proxy"});

  EXPECT_EQ(s.contains("::"), true);
  EXPECT_EQ(s.contains("alloc_sential_and_proxy"), true);
  EXPECT_EQ(s.contains("return"), true);
  EXPECT_EQ(s.contains("{-26.9876}"), true);

  /* Not found */
  EXPECT_EQ(s.contains(""), false);
  EXPECT_EQ(s.contains("uuuuu"), false);
}

/*
  std::pair<iterator,iterator> equal_range(const Key& key)
*/

TEST_F(TestMultiset, Equal_range_int) {
  my_stl::Multiset<int> s({1, 2, 2, 3, 3, 3});
  auto range = s.equal_range(3);

  int count = 0;
  for (auto it = range.first; it != range.second; ++it) {
    count++;
  }

  ASSERT_EQ(count, 3);
}

/*
  iterator lower_bound(const Key& key)
*/

TEST_F(TestMultiset, Lower_bound_int) {
  my_stl::Multiset<int> s({1, 2, 3, 4, 5});
  auto it = s.lower_bound(3);
  ASSERT_EQ(*it, 3);
}

/*
  iterator upper_bound(const Key& key)
*/

TEST_F(TestMultiset, Upper_bound_int) {
  my_stl::Multiset<int> s({1, 2, 3, 4, 5});
  auto it = s.upper_bound(3);
  ASSERT_EQ(*it, 4);
}