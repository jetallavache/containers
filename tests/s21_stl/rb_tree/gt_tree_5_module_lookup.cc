#include "gt_tree.h"

/*
  iterator find(const_value_reference value)
*/

TEST_F(TestTree, Find_return_iter_int) {
  s21::Tree<int, false> t;
  t.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});

  s21::Tree<int, false>::iterator it = t.find(-26);
  EXPECT_EQ(*it, -26);
  it = t.find(0);
  EXPECT_EQ(*it, 0);
  it = t.find(55);
  EXPECT_EQ(*it, 55);

  /* Not found */
  it = t.find(10000);
  EXPECT_EQ(it == t.end(), true);
  it = t.find(-2123);
  EXPECT_EQ(it == t.end(), true);
}

TEST_F(TestTree, Find_return_iter_double) {
  s21::Tree<double, false> t;
  t.insert({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876, 55.111111, 3.21,
            6.92929, -1, 0, -26.9876, 55.111111});

  s21::Tree<double, false>::iterator it = t.find(6.92929);
  EXPECT_EQ(*it, 6.92929);
  it = t.find(0);
  EXPECT_EQ(*it, 0);
  it = t.find(55.111111);
  EXPECT_EQ(*it, 55.111111);

  /* Not found */
  it = t.find(55.1111);
  EXPECT_EQ(it == t.end(), true);
  it = t.find(-12.023921);
  EXPECT_EQ(it == t.end(), true);
}

TEST_F(TestTree, Find_return_iter_string) {
  s21::Tree<std::string, false> t;
  t.insert({"s21", "::", "::", "::", "alloc_sential_and_proxy", "()",
            "{-26.9876}", "return", "s21", "::", "alloc_sential_and_proxy"});

  s21::Tree<std::string, false>::iterator it = t.find("::");
  EXPECT_EQ(*it, "::");
  it = t.find("return");
  EXPECT_EQ(*it, "return");
  it = t.find("alloc_sential_and_proxy");
  EXPECT_EQ(*it, "alloc_sential_and_proxy");

  /* Not found */
  it = t.find("alloc_sential_and");
  EXPECT_EQ(it == t.end(), true);
  it = t.find("");
  EXPECT_EQ(it == t.end(), true);
}

/*
  const_iterator find(const_value_reference value) const
*/

TEST_F(TestTree, Find_return_const_iter_int) {
  s21::Tree<int, false> t;
  t.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});

  s21::Tree<int, false>::const_iterator it = t.find(-26);
  EXPECT_EQ(*it, -26);
  it = t.find(0);
  EXPECT_EQ(*it, 0);
  it = t.find(55);
  EXPECT_EQ(*it, 55);

  /* Not found */
  it = t.find(10000);
  EXPECT_EQ(it == t.end(), true);
  it = t.find(-2123);
  EXPECT_EQ(it == t.end(), true);
}

TEST_F(TestTree, Find_return_const_iter_double) {
  s21::Tree<double, false> t;
  t.insert({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876, 55.111111, 3.21,
            6.92929, -1, 0, -26.9876, 55.111111});

  s21::Tree<double, false>::const_iterator it = t.find(6.92929);
  EXPECT_EQ(*it, 6.92929);
  it = t.find(0);
  EXPECT_EQ(*it, 0);
  it = t.find(55.111111);
  EXPECT_EQ(*it, 55.111111);

  /* Not found */
  it = t.find(55.1111);
  EXPECT_EQ(it == t.end(), true);
  it = t.find(-12.023921);
  EXPECT_EQ(it == t.end(), true);
}

TEST_F(TestTree, Find_return_const__iter_string) {
  s21::Tree<std::string, false> t;
  t.insert({"s21", "::", "::", "::", "alloc_sential_and_proxy", "()",
            "{-26.9876}", "return", "s21", "::", "alloc_sential_and_proxy"});

  s21::Tree<std::string, false>::const_iterator it = t.find("::");
  EXPECT_EQ(*it, "::");
  it = t.find("return");
  EXPECT_EQ(*it, "return");
  it = t.find("alloc_sential_and_proxy");
  EXPECT_EQ(*it, "alloc_sential_and_proxy");

  /* Not found */
  it = t.find("alloc_sential_and");
  EXPECT_EQ(it == t.end(), true);
  it = t.find("");
  EXPECT_EQ(it == t.end(), true);
}

/*
  bool contains(const Key& key)
*/

TEST_F(TestTree, Contains_int) {
  s21::Tree<int, false> s;
  s.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});

  EXPECT_EQ(s.contains(6), true);
  EXPECT_EQ(s.contains(-1), true);
  EXPECT_EQ(s.contains(55), true);
  EXPECT_EQ(s.contains(0), true);

  /* Not found */
  EXPECT_EQ(s.contains(60), false);
  EXPECT_EQ(s.contains(-100), false);
}

TEST_F(TestTree, Contains_double) {
  s21::Tree<double, false> s;
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

TEST_F(TestTree, Contains_string) {
  s21::Tree<std::string, false> s;
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