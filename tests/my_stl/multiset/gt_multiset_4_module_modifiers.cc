#include "gt_multiset.h"

/*
  void clear()
*/

TEST_F(TestMultiset, Clear_int) {
  my_stl::Multiset<int> s;
  s.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});
  EXPECT_EQ(s.empty(), false);

  s.clear();
  EXPECT_EQ(s.empty(), true);
}

TEST_F(TestMultiset, Clear_double) {
  my_stl::Multiset<double> s;
  s.insert({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876, 55.111111, 3.21,
            6.92929, -1, 0, -26.9876, 55.111111});
  EXPECT_EQ(s.empty(), false);

  s.clear();
  EXPECT_EQ(s.empty(), true);
}

TEST_F(TestMultiset, Clear_string) {
  my_stl::Multiset<std::string> s;
  s.insert({"my_stl", "::", "::", "::", "alloc_sential_and_proxy", "()",
            "{-26.9876}", "return", "my_stl", "::", "alloc_sential_and_proxy"});
  EXPECT_EQ(s.empty(), false);

  s.clear();
  EXPECT_EQ(s.empty(), true);
}

/*
  void insert(std::initializer_list<value_type> ilist)
*/

TEST_F(TestMultiset, Insert_initializer_list_int) {
  my_stl::Multiset<int> s1;
  s1.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});
  std::multiset<int> s2(
      {3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});

  MULTISET_EXPECT_EQ(s1, s2);

  EXPECT_EQ(17, (int)s1.size());
}

TEST_F(TestMultiset, Insert_initializer_list_double) {
  my_stl::Multiset<double> s1;
  s1.insert({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876, 55.111111, 3.21,
             6.92929, -1, 0, -26.9876, 55.111111});
  std::multiset<double> s2({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876,
                            55.111111, 3.21, 6.92929, -1, 0, -26.9876,
                            55.111111});

  MULTISET_EXPECT_EQ(s1, s2);

  EXPECT_EQ(14, (int)s1.size());
}

TEST_F(TestMultiset, Insert_initializer_list_string) {
  my_stl::Multiset<std::string> s1;
  s1.insert({"my_stl", "::", "::", "::", "alloc_sential_and_proxy", "()",
             "{-26.9876}", "return", "my_stl",
             "::", "alloc_sential_and_proxy"});
  std::multiset<std::string> s2(
      {"my_stl", "::", "::", "::", "alloc_sential_and_proxy", "()",
       "{-26.9876}", "return", "my_stl", "::", "alloc_sential_and_proxy"});

  MULTISET_EXPECT_EQ(s1, s2);

  EXPECT_EQ(11, (int)s1.size());
}

/*
  std::pair<iterator, bool> insert(const_value_reference value)
*/

TEST_F(TestMultiset, Insert_value_int) {
  my_stl::Multiset<int> s;
  s.insert(39);
  s.insert(33);
  s.insert(39);
  s.insert(33);
  s.insert(-192);
  s.insert(-192);
  s.insert(-192);
  s.insert(-192);
  s.insert(654);
  s.insert(-192);
  s.insert(654);

  auto it = s.begin();
  EXPECT_EQ(*it++, -192);
  EXPECT_EQ(*it++, -192);
  EXPECT_EQ(*it++, -192);
  EXPECT_EQ(*it++, -192);
  EXPECT_EQ(*it++, -192);
  EXPECT_EQ(*it++, 33);
  EXPECT_EQ(*it++, 33);
  EXPECT_EQ(*it++, 39);
  EXPECT_EQ(*it++, 39);
  EXPECT_EQ(*it++, 654);
  EXPECT_EQ(*it++, 654);

  EXPECT_EQ(11, (int)s.size());
}

TEST_F(TestMultiset, Insert_input_iter_int) {
  my_stl::Multiset<int> s1;
  s1.insert({3, 6, -1, 0, -26, 55});

  my_stl::Multiset<int> s2;
  s2.insert(s1.begin(), s1.end());

  MULTISET_EXPECT_EQ(s1, s2);

  EXPECT_EQ(6, (int)s2.size());
}

/*
  size_type erase(const_iterator pos)
*/

TEST_F(TestMultiset, Erase_int) {
  my_stl::Multiset<int> s1({-5, 7, -3, 2, -3, -5, 7, -4, -5});
  std::multiset<int> s2({-5, 7, -3, 2, -3, -5, 7, -4, -5});

  s1.erase(s1.find(2));
  s2.erase(s2.find(2));

  s1.erase(s1.find(-5));
  s2.erase(s2.find(-5));

  ASSERT_EQ(s1.size(), s2.size());
}

TEST_F(TestMultiset, Erase_int_delete_all) {
  my_stl::Multiset<int> s;
  s.insert({-5, 7, -3, 2, -3, -5, 7, -4, -5});

  s.erase(s.find(-5));
  s.erase(s.find(-5));
  s.erase(s.find(-5));
  s.erase(s.find(7));
  s.erase(s.find(7));
  s.erase(s.find(-3));
  s.erase(s.find(-3));
  s.erase(s.find(2));
  s.erase(s.find(-4));

  EXPECT_EQ((int)s.size(), 0);
  EXPECT_EQ(s.empty(), true);
}

/*
  void swap(set& other)
*/

TEST_F(TestMultiset, Swap_int) {
  my_stl::Multiset<int> expect_left({3, 5, 7, 9, 11, 23, 4, 0, 7, 7, -98});
  my_stl::Multiset<int> expect_right({-5, -5, -5, 1, 1});

  my_stl::Multiset<int> s_left({-5, -5, -5, 1, 1});
  my_stl::Multiset<int> s_right({3, 5, 7, 9, 11, 23, 4, 0, 7, 7, -98});

  s_left.swap(s_right);

  MULTISET_EXPECT_EQ(expect_left, s_left);
  MULTISET_EXPECT_EQ(expect_right, s_right);
}

TEST_F(TestMultiset, Swap_double) {
  my_stl::Multiset<double> expect_left(
      {-5.1, 11.9, -1.3, 1.4, 11.9, 5.6, 7.7, 9.8, 11.9, 11.9});
  my_stl::Multiset<double> expect_right({-1.312, 1.412, -1.312});

  my_stl::Multiset<double> s_left({-1.312, 1.412, -1.312});
  my_stl::Multiset<double> s_right(
      {-5.1, 11.9, -1.3, 1.4, 11.9, 5.6, 7.7, 9.8, 11.9, 11.9});

  s_left.swap(s_right);

  MULTISET_EXPECT_EQ(expect_left, s_left);
  MULTISET_EXPECT_EQ(expect_right, s_right);
}

TEST_F(TestMultiset, Swap_string) {
  my_stl::Multiset<std::string> expect_left({"woiweu3", "woiweu3", "qaz34",
                                             "09--wk", "12+kls", "ncls()",
                                             "@#$F", "woiweu3"});
  my_stl::Multiset<std::string> expect_right({"woiweu3", "woiweu3", "09--wk"});

  my_stl::Multiset<std::string> s_left({"woiweu3", "woiweu3", "09--wk"});
  my_stl::Multiset<std::string> s_right({"woiweu3", "woiweu3", "qaz34",
                                         "09--wk", "12+kls", "ncls()", "@#$F",
                                         "woiweu3"});

  s_left.swap(s_right);

  MULTISET_EXPECT_EQ(expect_left, s_left);
  MULTISET_EXPECT_EQ(expect_right, s_right);
}

/*
  void merge(set& other);
*/

TEST_F(TestMultiset, Merge_int) {
  my_stl::Multiset<int> s_union({-5, -3, -1, 1, 3, 5, 7, 9, 11, 23});
  my_stl::Multiset<int> s_left({-5, -3, -1, 1});
  my_stl::Multiset<int> s_right({3, 5, 7, 9, 11, 23});

  s_left.merge(s_right);
  MULTISET_EXPECT_EQ(s_union, s_left);
}

TEST_F(TestMultiset, Merge_double) {
  my_stl::Multiset<double> s_union(
      {-5.1, -3.2, -1.3, 1.4, 3.5, 5.6, 7.7, 9.8, 11.9, 23.1});
  my_stl::Multiset<double> s_left({-5.1, -3.2, -1.3, 1.4});
  my_stl::Multiset<double> s_right({3.5, 5.6, 7.7, 9.8, 11.9, 23.1});

  s_left.merge(s_right);
  MULTISET_EXPECT_EQ(s_union, s_left);
}

TEST_F(TestMultiset, Merge_string) {
  my_stl::Multiset<std::string> s_union({"dssw", "woiweu3", "qaz34", "09--wk",
                                         "12+kls", "ncls()", "@#$F", "ddkjhd"});
  my_stl::Multiset<std::string> s_left({"dssw", "woiweu3"});
  my_stl::Multiset<std::string> s_right(
      {"qaz34", "09--wk", "12+kls", "ncls()", "@#$F", "ddkjhd"});

  s_left.merge(s_right);
  MULTISET_EXPECT_EQ(s_union, s_left);
}
