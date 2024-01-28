#include "gt_tree.h"

/*
  void clear()
*/

TEST_F(TestTree, Clear_int) {
  s21::Tree<int, false> t;
  t.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});
  EXPECT_EQ(t.empty(), false);

  t.clear();
  EXPECT_EQ(t.empty(), true);
}

TEST_F(TestTree, Clear_double) {
  s21::Tree<double, false> t;
  t.insert({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876, 55.111111, 3.21,
            6.92929, -1, 0, -26.9876, 55.111111});
  EXPECT_EQ(t.empty(), false);

  t.clear();
  EXPECT_EQ(t.empty(), true);
}

TEST_F(TestTree, Clear_string) {
  s21::Tree<std::string, false> t;
  t.insert({"s21", "::", "::", "::", "alloc_sential_and_proxy", "()",
            "{-26.9876}", "return", "s21", "::", "alloc_sential_and_proxy"});
  EXPECT_EQ(t.empty(), false);

  t.clear();
  EXPECT_EQ(t.empty(), true);
}

/*
  void insert(std::initializer_list<value_type> ilist)
*/

TEST_F(TestTree, Insert_initializer_list_int) {
  s21::Tree<int, false> t1;
  t1.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});
  std::set<int> s1(
      {3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});

  auto t1_it = t1.begin();
  auto s1_it = s1.begin();
  for (; t1_it != t1.end(); ++t1_it, ++s1_it) {
    EXPECT_EQ(*t1_it, *s1_it);
  }
  EXPECT_EQ(6, (int)t1.size());
}

TEST_F(TestTree, Insert_initializer_list_double) {
  s21::Tree<double, false> t2;
  t2.insert({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876, 55.111111, 3.21,
             6.92929, -1, 0, -26.9876, 55.111111});
  std::set<double> s2({3.21, 6.92929, 6.92929, 6.92929, -1, 0, -26.9876,
                       55.111111, 3.21, 6.92929, -1, 0, -26.9876, 55.111111});

  auto t2_it = t2.begin();
  auto s2_it = s2.begin();
  for (; t2_it != t2.end(); ++t2_it, ++s2_it) {
    EXPECT_DOUBLE_EQ(*t2_it, *s2_it);
  }
  EXPECT_EQ(6, (int)t2.size());
}

TEST_F(TestTree, Insert_initializer_list_string) {
  s21::Tree<std::string, false> t3;
  t3.insert({"s21", "::", "::", "::", "alloc_sential_and_proxy", "()",
             "{-26.9876}", "return", "s21", "::", "alloc_sential_and_proxy"});
  std::set<std::string> s3({"s21", "::", "::", "::", "alloc_sential_and_proxy",
                            "()", "{-26.9876}", "return", "s21",
                            "::", "alloc_sential_and_proxy"});

  auto t3_it = t3.begin();
  auto s3_it = s3.begin();
  for (; t3_it != t3.end(); ++t3_it, ++s3_it) {
    EXPECT_EQ(*t3_it, *s3_it);
  }
  EXPECT_EQ(6, (int)t3.size());
}

/*
  std::pair<iterator, bool> insert(const_value_reference value)
*/

TEST_F(TestTree, Insert_value_int) {
  s21::Tree<int, false> t;
  t.insert(39);
  t.insert(33);
  t.insert(39);
  t.insert(33);
  t.insert(-192);
  t.insert(-192);
  t.insert(-192);
  t.insert(-192);
  t.insert(654);
  t.insert(-192);
  t.insert(654);

  auto it = t.begin();
  EXPECT_EQ(*it++, -192);
  EXPECT_EQ(*it++, 33);
  EXPECT_EQ(*it++, 39);
  EXPECT_EQ(*it++, 654);

  EXPECT_EQ(4, (int)t.size());
}

TEST_F(TestTree, Insert_value_int_what_return) {
  s21::Tree<int, false> t;

  auto pr = t.insert(12);
  EXPECT_EQ((pr.first == t.find(12)), true);
  EXPECT_EQ((pr.second), true);

  pr = t.insert(43);
  EXPECT_EQ((pr.first == t.find(43)), true);
  EXPECT_EQ((pr.second), true);

  pr = t.insert(43);
  EXPECT_EQ((pr.first == t.find(43)), true);
  EXPECT_EQ((pr.second), false);

  pr = t.insert(-1);
  EXPECT_EQ((pr.first == t.find(-1)), true);
  EXPECT_EQ((pr.second), true);
}

TEST_F(TestTree, Insert_value_double) {
  s21::Tree<double, false> t;
  t.insert(46573.1288804);
  t.insert(-473.98760001);
  t.insert(46573.1288804);
  t.insert(-473.98760001);
  t.insert(-0.000011);
  t.insert(-0.000011);
  t.insert(-0.000011);
  t.insert(-0.000011);
  t.insert(0.99999992);
  t.insert(-0.000011);
  t.insert(0.99999992);

  auto it = t.begin();
  EXPECT_DOUBLE_EQ(*it++, -473.98760001);
  EXPECT_DOUBLE_EQ(*it++, -0.000011);
  EXPECT_DOUBLE_EQ(*it++, 0.99999992);
  EXPECT_DOUBLE_EQ(*it++, 46573.1288804);

  EXPECT_EQ(4, (int)t.size());
}

TEST_F(TestTree, Insert_value_double_what_return) {
  s21::Tree<double, false> t;

  auto pr = t.insert(-0.000002);
  EXPECT_EQ((pr.first == t.find(-0.000002)), true);
  EXPECT_EQ((pr.second), true);

  pr = t.insert(9034.1111101);
  EXPECT_EQ((pr.first == t.find(9034.1111101)), true);
  EXPECT_EQ((pr.second), true);

  pr = t.insert(-0.000002);
  EXPECT_EQ((pr.first == t.find(-0.000002)), true);
  EXPECT_EQ((pr.second), false);

  pr = t.insert(-9034.1111101);
  EXPECT_EQ((pr.first == t.find(-9034.1111101)), true);
  EXPECT_EQ((pr.second), true);
}

TEST_F(TestTree, Insert_value_string) {
  s21::Tree<std::string, false> t;
  t.insert("Hello, my name is Eddacris");
  t.insert("12345678900-=)(*&^%$#@!`~");
  t.insert("Hello, my name is Eddacris");
  t.insert("12345678900-=)(*&^%$#@!`~");
  t.insert("program");
  t.insert("program");
  t.insert("program");
  t.insert("program");
  t.insert("program");

  auto it = t.begin();
  EXPECT_EQ(*it++, "12345678900-=)(*&^%$#@!`~");
  EXPECT_EQ(*it++, "Hello, my name is Eddacris");
  EXPECT_EQ(*it++, "program");

  EXPECT_EQ(3, (int)t.size());
}

TEST_F(TestTree, Insert_value_string_what_return) {
  s21::Tree<std::string, false> t;

  auto pr = t.insert("program");
  EXPECT_EQ((pr.first == t.find("program")), true);
  EXPECT_EQ((pr.second), true);

  pr = t.insert("12345678900-=)(*&^%$#@!`~");
  EXPECT_EQ((pr.first == t.find("12345678900-=)(*&^%$#@!`~")), true);
  EXPECT_EQ((pr.second), true);

  pr = t.insert("program");
  EXPECT_EQ((pr.first == t.find("program")), true);
  EXPECT_EQ((pr.second), false);

  pr = t.insert("Hello, my name is Eddacris");
  EXPECT_EQ((pr.first == t.find("Hello, my name is Eddacris")), true);
  EXPECT_EQ((pr.second), true);
}

/*
  template <class InputIt>
  void insert(InputIt first, InputIt last)
*/

TEST_F(TestTree, Insert_input_iter_int) {
  s21::Tree<int, false> t1;
  t1.insert({3, 6, -1, 0, -26, 55});

  s21::Tree<int, false> t2;
  t2.insert(t1.begin(), t1.end());

  auto it1 = t1.begin();
  for (auto it2 : t2) {
    EXPECT_EQ(*it1, it2);
    ++it1;
  }

  EXPECT_EQ(6, (int)t2.size());
}

/*
  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&...args)
*/

TEST_F(TestTree, Insert_many_int) {
  s21::Tree<int, false> t;
  std::vector<std::pair<s21::Tree<int, false>::iterator, bool>> v =
      t.insert_many(9, 9, 9, 23, 98, 23, 23, 1, 0, 0);

  EXPECT_EQ((int)t.size(), 5);

  EXPECT_EQ(*v[0].first, 9);
  EXPECT_EQ(v[0].second, true);

  EXPECT_EQ(*v[1].first, 9);
  EXPECT_EQ(v[1].second, false);

  EXPECT_EQ(*v[2].first, 9);
  EXPECT_EQ(v[2].second, false);

  EXPECT_EQ(*v[3].first, 23);
  EXPECT_EQ(v[3].second, true);

  EXPECT_EQ(*v[4].first, 98);
  EXPECT_EQ(v[4].second, true);

  EXPECT_EQ(*v[5].first, 23);
  EXPECT_EQ(v[5].second, false);

  EXPECT_EQ(*v[6].first, 23);
  EXPECT_EQ(v[6].second, false);

  EXPECT_EQ(*v[7].first, 1);
  EXPECT_EQ(v[7].second, true);

  EXPECT_EQ(*v[8].first, 0);
  EXPECT_EQ(v[8].second, true);

  EXPECT_EQ(*v[9].first, 0);
  EXPECT_EQ(v[9].second, false);
}

TEST_F(TestTree, Insert_many_double) {
  s21::Tree<double, false> t;
  std::vector<std::pair<s21::Tree<double, false>::iterator, bool>> v =
      t.insert_many(9.12, 9.12, 9.12, 23.09, 98.8, 23.09, 23.09, 1.2, 0.02,
                    0.02);

  EXPECT_EQ((int)t.size(), 5);

  EXPECT_EQ(*v[0].first, 9.12);
  EXPECT_EQ(v[0].second, true);

  EXPECT_EQ(*v[1].first, 9.12);
  EXPECT_EQ(v[1].second, false);

  EXPECT_EQ(*v[2].first, 9.12);
  EXPECT_EQ(v[2].second, false);

  EXPECT_EQ(*v[3].first, 23.09);
  EXPECT_EQ(v[3].second, true);

  EXPECT_EQ(*v[4].first, 98.8);
  EXPECT_EQ(v[4].second, true);

  EXPECT_EQ(*v[5].first, 23.09);
  EXPECT_EQ(v[5].second, false);

  EXPECT_EQ(*v[6].first, 23.09);
  EXPECT_EQ(v[6].second, false);

  EXPECT_EQ(*v[7].first, 1.2);
  EXPECT_EQ(v[7].second, true);

  EXPECT_EQ(*v[8].first, 0.02);
  EXPECT_EQ(v[8].second, true);

  EXPECT_EQ(*v[9].first, 0.02);
  EXPECT_EQ(v[9].second, false);
}

TEST_F(TestTree, Insert_many_string) {
  s21::Tree<std::string, false> t;
  std::vector<std::pair<s21::Tree<std::string, false>::iterator, bool>> v =
      t.insert_many("qwe", "qwe", "qwe", "654r", "aaa", "654r", "654r", "nbvbn",
                    "poi", "poi");

  EXPECT_EQ((int)t.size(), 5);

  EXPECT_EQ(*v[0].first, "qwe");
  EXPECT_EQ(v[0].second, true);

  EXPECT_EQ(*v[1].first, "qwe");
  EXPECT_EQ(v[1].second, false);

  EXPECT_EQ(*v[2].first, "qwe");
  EXPECT_EQ(v[2].second, false);

  EXPECT_EQ(*v[3].first, "654r");
  EXPECT_EQ(v[3].second, true);

  EXPECT_EQ(*v[4].first, "aaa");
  EXPECT_EQ(v[4].second, true);

  EXPECT_EQ(*v[5].first, "654r");
  EXPECT_EQ(v[5].second, false);

  EXPECT_EQ(*v[6].first, "654r");
  EXPECT_EQ(v[6].second, false);

  EXPECT_EQ(*v[7].first, "nbvbn");
  EXPECT_EQ(v[7].second, true);

  EXPECT_EQ(*v[8].first, "poi");
  EXPECT_EQ(v[8].second, true);

  EXPECT_EQ(*v[9].first, "poi");
  EXPECT_EQ(v[9].second, false);
}

/*
  size_type erase(const_iterator pos)
*/

TEST_F(TestTree, Erase_int) {
  s21::Tree<int, false> t;
  t.insert({3, 6, 6, 6, -1, 0, -26, 55, 3, 6, -1, 0, -26, 55, 55, 55, 55});

  auto it = t.find(55);
  EXPECT_EQ((*it == 55), true);
  t.erase(it);
  it = t.find(55);
  EXPECT_EQ((it == t.end()), true);

  it = t.find(6);
  EXPECT_EQ((*it == 6), true);
  t.erase(it);
  it = t.find(6);
  EXPECT_EQ((it == t.end()), true);

  it = t.find(-26);
  EXPECT_EQ((*it == -26), true);
  t.erase(it);
  it = t.find(-26);
  EXPECT_EQ((it == t.end()), true);

  it = t.find(2);
  EXPECT_EQ((it == t.end()), true);
  t.erase(it);
  EXPECT_EQ((it == t.end()), true);
}

TEST_F(TestTree, Erase_int_delete_all) {
  s21::Tree<int, false> t2;
  t2.insert({6, 7, -1, 2, -3, 8, 9, -4, -5});

  t2.erase(t2.find(6));
  t2.erase(t2.find(-1));
  t2.erase(t2.find(8));
  t2.erase(t2.find(2));
  t2.erase(t2.find(-4));
  t2.erase(t2.find(7));
  t2.erase(t2.find(-3));
  t2.erase(t2.find(-5));
  t2.erase(t2.find(9));
  EXPECT_EQ((int)t2.size(), 0);
  EXPECT_EQ(t2.empty(), true);

  t2.insert({3, 5, 10, -3});
  EXPECT_EQ((int)t2.size(), 4);
  EXPECT_EQ(t2.empty(), false);
}

TEST_F(TestTree, Erase_double) {
  s21::Tree<double, false> t;
  t.insert({3.21, 55.111111, 6.92929, -1, 0, -26.9876, 55.111111});

  auto it = t.find(6.92929);
  EXPECT_EQ((*it == 6.92929), true);
  t.erase(it);
  it = t.find(6.92929);
  EXPECT_EQ((it == t.end()), true);

  it = t.find(-26.9876);
  EXPECT_EQ((*it == -26.9876), true);
  t.erase(it);
  it = t.find(-26.9876);
  EXPECT_EQ((it == t.end()), true);

  it = t.find(3.21);
  EXPECT_EQ((*it == 3.21), true);
  t.erase(it);
  it = t.find(3.21);
  EXPECT_EQ((it == t.end()), true);

  it = t.find(0);
  EXPECT_EQ((*it == 0), true);
  t.erase(it);
  it = t.find(0);
  EXPECT_EQ((it == t.end()), true);

  it = t.find(2.01);
  EXPECT_EQ((it == t.end()), true);
  t.erase(it);
  EXPECT_EQ((it == t.end()), true);

  it = t.find(-1);
  EXPECT_EQ((*it == -1), true);
  t.erase(it);
  it = t.find(-1);
  EXPECT_EQ((it == t.end()), true);

  EXPECT_EQ((int)t.size(), 1);
}

TEST_F(TestTree, Erase_double_delete_all) {
  s21::Tree<double, false> t;
  t.insert({3.21, -26.98, 6.92, -1, 0, 55.11});

  t.erase(t.find(6.92));
  t.erase(t.find(-26.98));
  t.erase(t.find(3.21));
  t.erase(t.find(0));
  t.erase(t.find(-1));
  t.erase(t.find(55.11));
  EXPECT_EQ((int)t.size(), 0);
  EXPECT_EQ(t.empty(), true);

  t.insert({3.21, -26.98, 6.92, -1, 0, 55.11});
  EXPECT_EQ((int)t.size(), 6);
  EXPECT_EQ(t.empty(), false);
}

TEST_F(TestTree, Erase_string) {
  s21::Tree<std::string, false> t;
  t.insert(
      {"s21", "::", "alloc_sential_and_proxy", "()", "{-26.9876}", "return"});

  auto it = t.find("::");
  EXPECT_EQ((*it == "::"), true);
  t.erase(it);
  it = t.find("::");
  EXPECT_EQ((it == t.end()), true);

  it = t.find("{-26.9876}");
  EXPECT_EQ((*it == "{-26.9876}"), true);
  t.erase(it);
  it = t.find("{-26.9876}");
  EXPECT_EQ((it == t.end()), true);

  it = t.find("alloc_sential_and_proxy");
  EXPECT_EQ((*it == "alloc_sential_and_proxy"), true);
  t.erase(it);
  it = t.find("alloc_sential_and_proxy");
  EXPECT_EQ((it == t.end()), true);

  it = t.find("(9090909)");
  EXPECT_EQ((it == t.end()), true);
  t.erase(it);
  EXPECT_EQ((it == t.end()), true);

  it = t.find("()");
  EXPECT_EQ((*it == "()"), true);
  t.erase(it);
  it = t.find("()");
  EXPECT_EQ((it == t.end()), true);

  it = t.find("return");
  EXPECT_EQ((*it == "return"), true);
  t.erase(it);
  it = t.find("return");
  EXPECT_EQ((it == t.end()), true);

  it = t.find("s21");
  EXPECT_EQ((*it == "s21"), true);
  t.erase(it);
  it = t.find("s21");
  EXPECT_EQ((it == t.end()), true);

  EXPECT_EQ((int)t.size(), 0);
  EXPECT_EQ(t.empty(), true);
}