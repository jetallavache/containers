#include "gt_set.h"

/*
  void clear()
*/

TEST_F(TestSet, Clear_int) {
  my_stl::Set<int> s;
  s.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});
  EXPECT_EQ(s.empty(), false);

  s.clear();
  EXPECT_EQ(s.empty(), true);
}

TEST_F(TestSet, Clear_double) {
  my_stl::Set<double> s;
  s.insert({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876, 55.111111, 3.21,
            6.92929, -1, 0, -26.9876, 55.111111});
  EXPECT_EQ(s.empty(), false);

  s.clear();
  EXPECT_EQ(s.empty(), true);
}

TEST_F(TestSet, Clear_string) {
  my_stl::Set<std::string> s;
  s.insert({"my_stl", "::", "::", "::", "alloc_sential_and_proxy", "()",
            "{-26.9876}", "return", "my_stl", "::", "alloc_sential_and_proxy"});
  EXPECT_EQ(s.empty(), false);

  s.clear();
  EXPECT_EQ(s.empty(), true);
}

/*
  void insert(std::initializer_list<value_type> ilist)
*/

TEST_F(TestSet, Insert_initializer_list_int) {
  my_stl::Set<int> s1;
  s1.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});
  std::set<int> s2(
      {3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});

  SET_EXPECT_EQ(s1, s2);

  EXPECT_EQ(6, (int)s1.size());
}

TEST_F(TestSet, Insert_initializer_list_double) {
  my_stl::Set<double> s1;
  s1.insert({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876, 55.111111, 3.21,
             6.92929, -1, 0, -26.9876, 55.111111});
  std::set<double> s2({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876,
                       55.111111, 3.21, 6.92929, -1, 0, -26.9876, 55.111111});

  SET_EXPECT_EQ(s1, s2);

  EXPECT_EQ(6, (int)s1.size());
}

TEST_F(TestSet, Insert_initializer_list_string) {
  my_stl::Set<std::string> s1;
  s1.insert({"my_stl", "::", "::", "::", "alloc_sential_and_proxy", "()",
             "{-26.9876}", "return", "my_stl",
             "::", "alloc_sential_and_proxy"});
  std::set<std::string> s2(
      {"my_stl", "::", "::", "::", "alloc_sential_and_proxy", "()",
       "{-26.9876}", "return", "my_stl", "::", "alloc_sential_and_proxy"});

  SET_EXPECT_EQ(s1, s2);

  EXPECT_EQ(6, (int)s1.size());
}

/*
  std::pair<iterator, bool> insert(const_value_reference value)
*/

TEST_F(TestSet, Insert_value_int) {
  my_stl::Set<int> s;
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
  EXPECT_EQ(*it++, 33);
  EXPECT_EQ(*it++, 39);
  EXPECT_EQ(*it++, 654);

  EXPECT_EQ(4, (int)s.size());
}

TEST_F(TestSet, Insert_value_int_what_return) {
  my_stl::Set<int> s;

  auto pr = s.insert(12);
  EXPECT_EQ((pr.first == s.find(12)), true);
  EXPECT_EQ((pr.second), true);

  pr = s.insert(43);
  EXPECT_EQ((pr.first == s.find(43)), true);
  EXPECT_EQ((pr.second), true);

  pr = s.insert(43);
  EXPECT_EQ((pr.first == s.find(43)), true);
  EXPECT_EQ((pr.second), false);

  pr = s.insert(-1);
  EXPECT_EQ((pr.first == s.find(-1)), true);
  EXPECT_EQ((pr.second), true);
}

TEST_F(TestSet, Insert_value_double) {
  my_stl::Set<double> s;
  s.insert(46573.1288804);
  s.insert(-473.98760001);
  s.insert(46573.1288804);
  s.insert(-473.98760001);
  s.insert(-0.000011);
  s.insert(-0.000011);
  s.insert(-0.000011);
  s.insert(-0.000011);
  s.insert(0.99999992);
  s.insert(-0.000011);
  s.insert(0.99999992);

  auto it = s.begin();
  EXPECT_DOUBLE_EQ(*it++, -473.98760001);
  EXPECT_DOUBLE_EQ(*it++, -0.000011);
  EXPECT_DOUBLE_EQ(*it++, 0.99999992);
  EXPECT_DOUBLE_EQ(*it++, 46573.1288804);

  EXPECT_EQ(4, (int)s.size());
}

TEST_F(TestSet, Insert_value_double_what_return) {
  my_stl::Set<double> s;

  auto pr = s.insert(-0.000002);
  EXPECT_EQ((pr.first == s.find(-0.000002)), true);
  EXPECT_EQ((pr.second), true);

  pr = s.insert(9034.1111101);
  EXPECT_EQ((pr.first == s.find(9034.1111101)), true);
  EXPECT_EQ((pr.second), true);

  pr = s.insert(-0.000002);
  EXPECT_EQ((pr.first == s.find(-0.000002)), true);
  EXPECT_EQ((pr.second), false);

  pr = s.insert(-9034.1111101);
  EXPECT_EQ((pr.first == s.find(-9034.1111101)), true);
  EXPECT_EQ((pr.second), true);
}

TEST_F(TestSet, Insert_value_string) {
  my_stl::Set<std::string> s;
  s.insert("Hello, my name is Eddacris");
  s.insert("12345678900-=)(*&^%$#@!`~");
  s.insert("Hello, my name is Eddacris");
  s.insert("12345678900-=)(*&^%$#@!`~");
  s.insert("program");
  s.insert("program");
  s.insert("program");
  s.insert("program");
  s.insert("program");

  auto it = s.begin();
  EXPECT_EQ(*it++, "12345678900-=)(*&^%$#@!`~");
  EXPECT_EQ(*it++, "Hello, my name is Eddacris");
  EXPECT_EQ(*it++, "program");

  EXPECT_EQ(3, (int)s.size());
}

TEST_F(TestSet, Insert_value_string_what_return) {
  my_stl::Set<std::string> s;

  auto pr = s.insert("program");
  EXPECT_EQ((pr.first == s.find("program")), true);
  EXPECT_EQ((pr.second), true);

  pr = s.insert("12345678900-=)(*&^%$#@!`~");
  EXPECT_EQ((pr.first == s.find("12345678900-=)(*&^%$#@!`~")), true);
  EXPECT_EQ((pr.second), true);

  pr = s.insert("program");
  EXPECT_EQ((pr.first == s.find("program")), true);
  EXPECT_EQ((pr.second), false);

  pr = s.insert("Hello, my name is Eddacris");
  EXPECT_EQ((pr.first == s.find("Hello, my name is Eddacris")), true);
  EXPECT_EQ((pr.second), true);
}

/*
  template <class InputIt>
  void insert(InputIt first, InputIt last)
*/

TEST_F(TestSet, Insert_input_iter_int) {
  my_stl::Set<int> s1;
  s1.insert({3, 6, -1, 0, -26, 55});

  my_stl::Set<int> s2;
  s2.insert(s1.begin(), s1.end());

  SET_EXPECT_EQ(s1, s2);

  EXPECT_EQ(6, (int)s2.size());
}

/*
  size_type erase(const_iterator pos)
*/

TEST_F(TestSet, Erase_int) {
  my_stl::Set<int> s;
  s.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});

  auto it = s.find(55);
  EXPECT_EQ((*it == 55), true);
  s.erase(it);
  it = s.find(55);
  EXPECT_EQ((it == s.end()), true);

  it = s.find(6);
  EXPECT_EQ((*it == 6), true);
  s.erase(it);
  it = s.find(6);
  EXPECT_EQ((it == s.end()), true);

  it = s.find(-26);
  EXPECT_EQ((*it == -26), true);
  s.erase(it);
  it = s.find(-26);
  EXPECT_EQ((it == s.end()), true);

  it = s.find(2);
  EXPECT_EQ((it == s.end()), true);
  s.erase(it);
  EXPECT_EQ((it == s.end()), true);
}

TEST_F(TestSet, Erase_int_delete_all) {
  my_stl::Set<int> s;
  s.insert({6, 7, -1, 2, -3, 8, 9, -4, -5});

  s.erase(s.find(6));
  s.erase(s.find(-1));
  s.erase(s.find(8));
  s.erase(s.find(2));
  s.erase(s.find(-4));
  s.erase(s.find(7));
  s.erase(s.find(-3));
  s.erase(s.find(-5));
  s.erase(s.find(9));
  EXPECT_EQ((int)s.size(), 0);
  EXPECT_EQ(s.empty(), true);

  s.insert({3, 5, 10, -3});
  EXPECT_EQ((int)s.size(), 4);
  EXPECT_EQ(s.empty(), false);
}

TEST_F(TestSet, Erase_double) {
  my_stl::Set<double> s;
  s.insert({3.21, 55.111111, 6.92929, -1, 0, -26.9876, 55.111111});

  auto it = s.find(6.92929);
  EXPECT_EQ((*it == 6.92929), true);
  s.erase(it);
  it = s.find(6.92929);
  EXPECT_EQ((it == s.end()), true);

  it = s.find(-26.9876);
  EXPECT_EQ((*it == -26.9876), true);
  s.erase(it);
  it = s.find(-26.9876);
  EXPECT_EQ((it == s.end()), true);

  it = s.find(3.21);
  EXPECT_EQ((*it == 3.21), true);
  s.erase(it);
  it = s.find(3.21);
  EXPECT_EQ((it == s.end()), true);

  it = s.find(0);
  EXPECT_EQ((*it == 0), true);
  s.erase(it);
  it = s.find(0);
  EXPECT_EQ((it == s.end()), true);

  it = s.find(2.01);
  EXPECT_EQ((it == s.end()), true);
  s.erase(it);
  EXPECT_EQ((it == s.end()), true);

  it = s.find(-1);
  EXPECT_EQ((*it == -1), true);
  s.erase(it);
  it = s.find(-1);
  EXPECT_EQ((it == s.end()), true);

  EXPECT_EQ((int)s.size(), 1);
}

TEST_F(TestSet, Erase_double_delete_all) {
  my_stl::Set<double> s;
  s.insert({3.21, -26.98, 6.92, -1, 0, 55.11});

  s.erase(s.find(6.92));
  s.erase(s.find(-26.98));
  s.erase(s.find(3.21));
  s.erase(s.find(0));
  s.erase(s.find(-1));
  s.erase(s.find(55.11));
  EXPECT_EQ((int)s.size(), 0);
  EXPECT_EQ(s.empty(), true);

  s.insert({3.21, -26.98, 6.92, -1, 0, 55.11});
  EXPECT_EQ((int)s.size(), 6);
  EXPECT_EQ(s.empty(), false);
}

TEST_F(TestSet, Erase_string) {
  my_stl::Set<std::string> s;
  s.insert({"my_stl", "::", "alloc_sential_and_proxy", "()", "{-26.9876}",
            "return"});

  auto it = s.find("::");
  EXPECT_EQ((*it == "::"), true);
  s.erase(it);
  it = s.find("::");
  EXPECT_EQ((it == s.end()), true);

  it = s.find("{-26.9876}");
  EXPECT_EQ((*it == "{-26.9876}"), true);
  s.erase(it);
  it = s.find("{-26.9876}");
  EXPECT_EQ((it == s.end()), true);

  it = s.find("alloc_sential_and_proxy");
  EXPECT_EQ((*it == "alloc_sential_and_proxy"), true);
  s.erase(it);
  it = s.find("alloc_sential_and_proxy");
  EXPECT_EQ((it == s.end()), true);

  it = s.find("(9090909)");
  EXPECT_EQ((it == s.end()), true);
  s.erase(it);
  EXPECT_EQ((it == s.end()), true);

  it = s.find("()");
  EXPECT_EQ((*it == "()"), true);
  s.erase(it);
  it = s.find("()");
  EXPECT_EQ((it == s.end()), true);

  it = s.find("return");
  EXPECT_EQ((*it == "return"), true);
  s.erase(it);
  it = s.find("return");
  EXPECT_EQ((it == s.end()), true);

  it = s.find("my_stl");
  EXPECT_EQ((*it == "my_stl"), true);
  s.erase(it);
  it = s.find("my_stl");
  EXPECT_EQ((it == s.end()), true);

  EXPECT_EQ((int)s.size(), 0);
  EXPECT_EQ(s.empty(), true);
}

/*
  void swap(set& other)
*/

TEST_F(TestSet, Swap_int) {
  my_stl::Set<int> expect_left({3, 5, 7, 9, 11, 23, 4, 0, 12, 23, -98});
  my_stl::Set<int> expect_right({-5, -3, -1, 1});

  my_stl::Set<int> s_left({-5, -3, -1, 1});
  my_stl::Set<int> s_right({3, 5, 7, 9, 11, 23, 4, 0, 12, 23, -98});

  s_left.swap(s_right);

  SET_EXPECT_EQ(expect_left, s_left);
  SET_EXPECT_EQ(expect_right, s_right);
}

TEST_F(TestSet, Swap_double) {
  my_stl::Set<double> expect_left(
      {-5.1, -3.2, -1.3, 1.4, 3.5, 5.6, 7.7, 9.8, 11.9, 23.1});
  my_stl::Set<double> expect_right({-1.312, 1.412, 3.512});

  my_stl::Set<double> s_left({-1.312, 1.412, 3.512});
  my_stl::Set<double> s_right(
      {-5.1, -3.2, -1.3, 1.4, 3.5, 5.6, 7.7, 9.8, 11.9, 23.1});

  s_left.swap(s_right);

  SET_EXPECT_EQ(expect_left, s_left);
  SET_EXPECT_EQ(expect_right, s_right);
}

TEST_F(TestSet, Swap_string) {
  my_stl::Set<std::string> expect_left({"dssw", "woiweu3", "qaz34", "09--wk",
                                        "12+kls", "ncls()", "@#$F", "ddkjhd"});
  my_stl::Set<std::string> expect_right({"woiweu3", "qaz34", "09--wk"});

  my_stl::Set<std::string> s_left({"woiweu3", "qaz34", "09--wk"});
  my_stl::Set<std::string> s_right({"dssw", "woiweu3", "qaz34", "09--wk",
                                    "12+kls", "ncls()", "@#$F", "ddkjhd"});

  s_left.swap(s_right);

  SET_EXPECT_EQ(expect_left, s_left);
  SET_EXPECT_EQ(expect_right, s_right);
}

/*
  void merge(set& other);
*/

TEST_F(TestSet, Merge_int) {
  my_stl::Set<int> s_union({-5, -3, -1, 1, 3, 5, 7, 9, 11, 23});
  my_stl::Set<int> s_left({-5, -3, -1, 1});
  my_stl::Set<int> s_right({3, 5, 7, 9, 11, 23});

  s_left.merge(s_right);
  SET_EXPECT_EQ(s_union, s_left);
}

TEST_F(TestSet, Merge_double) {
  my_stl::Set<double> s_union(
      {-5.1, -3.2, -1.3, 1.4, 3.5, 5.6, 7.7, 9.8, 11.9, 23.1});
  my_stl::Set<double> s_left({-5.1, -3.2, -1.3, 1.4});
  my_stl::Set<double> s_right({3.5, 5.6, 7.7, 9.8, 11.9, 23.1});

  s_left.merge(s_right);
  SET_EXPECT_EQ(s_union, s_left);
}

TEST_F(TestSet, Merge_string) {
  my_stl::Set<std::string> s_union({"dssw", "woiweu3", "qaz34", "09--wk",
                                    "12+kls", "ncls()", "@#$F", "ddkjhd"});
  my_stl::Set<std::string> s_left({"dssw", "woiweu3"});
  my_stl::Set<std::string> s_right(
      {"qaz34", "09--wk", "12+kls", "ncls()", "@#$F", "ddkjhd"});

  s_left.merge(s_right);
  SET_EXPECT_EQ(s_union, s_left);
}
