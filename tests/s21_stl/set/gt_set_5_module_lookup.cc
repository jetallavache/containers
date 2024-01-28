#include "gt_set.h"

/*
  iterator find(const_value_reference value)
*/

TEST_F(TestSet, Find_return_iter_int) {
  s21::Set<int> s;
  s.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});

  s21::Set<int>::iterator it = s.find(-26);
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

TEST_F(TestSet, Find_return_iter_double) {
  s21::Set<double> s;
  s.insert({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876, 55.111111, 3.21,
            6.92929, -1, 0, -26.9876, 55.111111});

  s21::Set<double>::iterator it = s.find(6.92929);
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

TEST_F(TestSet, Find_return_iter_string) {
  s21::Set<std::string> s;
  s.insert({"s21", "::", "::", "::", "alloc_sential_and_proxy", "()",
            "{-26.9876}", "return", "s21", "::", "alloc_sential_and_proxy"});

  s21::Set<std::string>::iterator it = s.find("::");
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

TEST_F(TestSet, Find_return_const_iter_int) {
  s21::Set<int> s;
  s.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});

  s21::Set<int>::const_iterator it = s.find(-26);
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

TEST_F(TestSet, Find_return_const_iter_double) {
  s21::Set<double> s;
  s.insert({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876, 55.111111, 3.21,
            6.92929, -1, 0, -26.9876, 55.111111});

  s21::Set<double>::const_iterator it = s.find(6.92929);
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

TEST_F(TestSet, Find_returnconst__iter_string) {
  s21::Set<std::string> s;
  s.insert({"s21", "::", "::", "::", "alloc_sential_and_proxy", "()",
            "{-26.9876}", "return", "s21", "::", "alloc_sential_and_proxy"});

  s21::Set<std::string>::const_iterator it = s.find("::");
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

TEST_F(TestSet, Contains_int) {
  s21::Set<int> s;
  s.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});

  EXPECT_EQ(s.contains(6), true);
  EXPECT_EQ(s.contains(-1), true);
  EXPECT_EQ(s.contains(55), true);
  EXPECT_EQ(s.contains(0), true);

  /* Not found */
  EXPECT_EQ(s.contains(60), false);
  EXPECT_EQ(s.contains(-100), false);
}

TEST_F(TestSet, Contains_double) {
  s21::Set<double> s;
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

TEST_F(TestSet, Contains_string) {
  s21::Set<std::string> s;
  s.insert({"s21", "::", "::", "::", "alloc_sential_and_proxy", "()",
            "{-26.9876}", "return", "s21", "::", "alloc_sential_and_proxy"});

  EXPECT_EQ(s.contains("::"), true);
  EXPECT_EQ(s.contains("alloc_sential_and_proxy"), true);
  EXPECT_EQ(s.contains("return"), true);
  EXPECT_EQ(s.contains("{-26.9876}"), true);

  /* Not found */
  EXPECT_EQ(s.contains(""), false);
  EXPECT_EQ(s.contains("uuuuu"), false);
}
