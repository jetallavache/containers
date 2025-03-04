#include "gt_multiset.h"

/* Default constructor */
TEST_F(TestMultiset, Constructor_default_int) {
  my_stl::Multiset<int> s1;
  EXPECT_EQ(0, (int)s1.size());
}

TEST_F(TestMultiset, Constructor_default_double) {
  my_stl::Multiset<double> s1;
  EXPECT_EQ(0, (int)s1.size());
}

TEST_F(TestMultiset, Constructor_default_string) {
  my_stl::Multiset<std::string> s1;
  EXPECT_EQ(0, (int)s1.size());
}

/* With Allocator */
TEST_F(TestMultiset, Constructor_allocator_int) {
  my_stl::Multiset<int> s1;
  my_stl::Multiset<int>::allocator_type s_alloc;

  s_alloc = s1.get_allocator();

  my_stl::Multiset<int> s2(s_alloc);

  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.get_allocator(), s2.get_allocator());
}

TEST_F(TestMultiset, Constructor_allocator_double) {
  my_stl::Multiset<double> s1;
  my_stl::Multiset<double>::allocator_type s_alloc;

  s_alloc = s1.get_allocator();

  my_stl::Multiset<double> s2(s_alloc);

  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.get_allocator(), s2.get_allocator());
}

TEST_F(TestMultiset, Constructor_allocator_string) {
  my_stl::Multiset<std::string> s1;
  my_stl::Multiset<std::string>::allocator_type s_alloc;

  s_alloc = s1.get_allocator();

  my_stl::Multiset<std::string> s2(s_alloc);

  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.get_allocator(), s2.get_allocator());
}

/* Initializer list */
TEST_F(TestMultiset, Constructor_initializer_list_int) {
  my_stl::Multiset<int> s1({1, 2, 7, 9, 0, 12, -3, -6});
  std::multiset<int> s2({1, 2, 7, 9, 0, 12, -3, -6});

  MULTISET_EXPECT_EQ(s1, s2);

  EXPECT_EQ(8, (int)s1.size());
}

TEST_F(TestMultiset, Constructor_initializer_list_equal_int) {
  my_stl::Multiset<int> s1 = {1, 2, 7, 9, 0, 12, -3, -6};
  std::multiset<int> s2 = {1, 2, 7, 9, 0, 12, -3, -6};

  MULTISET_EXPECT_EQ(s1, s2);

  EXPECT_EQ(8, (int)s1.size());
}

/* Copy constructor*/
TEST_F(TestMultiset, Constructor_copy_int) {
  my_stl::Multiset<int> s1;
  s1.insert(5);
  s1.insert(6);

  my_stl::Multiset<int> s2(s1);

  EXPECT_EQ(*s1.begin(), *s2.begin());
  EXPECT_EQ(*s1.end(), *s2.end());
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.get_allocator(), s2.get_allocator());
}

TEST_F(TestMultiset, Constructor_copy_double) {
  my_stl::Multiset<double> s1;
  s1.insert(0.129834);
  s1.insert(-1.000001);

  my_stl::Multiset<double> s2(s1);

  EXPECT_DOUBLE_EQ(*s1.begin(), *s2.begin());
  EXPECT_DOUBLE_EQ(*s1.end(), *s2.end());
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.get_allocator(), s2.get_allocator());
}

TEST_F(TestMultiset, Constructor_copy_string) {
  my_stl::Multiset<std::string> s1;
  s1.insert("Hello, ");
  s1.insert("World!");

  my_stl::Multiset<std::string> s2(s1);

  EXPECT_EQ(*s1.begin(), *s2.begin());
  EXPECT_EQ(*s1.end(), *s2.end());
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.get_allocator(), s2.get_allocator());
}

/* Copy equal */
TEST_F(TestMultiset, Constructor_copy_equal_int) {
  my_stl::Multiset<int> s1;
  s1.insert(5);
  s1.insert(6);

  my_stl::Multiset<int> s2 = s1;

  EXPECT_EQ(*s1.begin(), *s2.begin());
  EXPECT_EQ(*s1.end(), *s2.end());
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.get_allocator(), s2.get_allocator());
}

TEST_F(TestMultiset, Constructor_copy_equal_double) {
  my_stl::Multiset<double> s1;
  s1.insert(0.129834);
  s1.insert(-1.000001);

  my_stl::Multiset<double> s2 = s1;

  EXPECT_DOUBLE_EQ(*s1.begin(), *s2.begin());
  EXPECT_DOUBLE_EQ(*s1.end(), *s2.end());
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.get_allocator(), s2.get_allocator());
}

TEST_F(TestMultiset, Constructor_copy_equal_string) {
  my_stl::Multiset<std::string> s1;
  s1.insert("Hello, ");
  s1.insert("World!");

  my_stl::Multiset<std::string> s2 = s1;

  EXPECT_EQ(*s1.begin(), *s2.begin());
  EXPECT_EQ(*s1.end(), *s2.end());
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.get_allocator(), s2.get_allocator());
}

/* Move constructor */
TEST_F(TestMultiset, Constructor_move_int) {
  my_stl::Multiset<int> s1;
  s1.insert(5);
  s1.insert(6);

  my_stl::Multiset<int> s2(std::move(s1));

  EXPECT_EQ(true, s1.empty());
  EXPECT_EQ(*s2.begin(), 5);
  EXPECT_EQ(*++s2.begin(), 6);
  EXPECT_EQ(0, (int)s1.size());
  EXPECT_EQ(2, (int)s2.size());
}

TEST_F(TestMultiset, Constructor_move_double) {
  my_stl::Multiset<double> s1;
  s1.insert(-999.999212);
  s1.insert(0.000012);

  my_stl::Multiset<double> s2(std::move(s1));

  EXPECT_EQ(true, s1.empty());
  EXPECT_DOUBLE_EQ(*s2.begin(), -999.999212);
  EXPECT_DOUBLE_EQ(*++s2.begin(), 0.000012);
  EXPECT_EQ(0, (int)s1.size());
  EXPECT_EQ(2, (int)s2.size());
}

TEST_F(TestMultiset, Constructor_move_string) {
  my_stl::Multiset<std::string> s1;
  s1.insert("Hello, ");
  s1.insert("World!");

  my_stl::Multiset<std::string> s2(std::move(s1));

  EXPECT_EQ(true, s1.empty());
  EXPECT_EQ(*s2.begin(), "Hello, ");
  EXPECT_EQ(*++s2.begin(), "World!");
  EXPECT_EQ(0, (int)s1.size());
  EXPECT_EQ(2, (int)s2.size());
}

/* Move equal */
TEST_F(TestMultiset, Constructor_move_equal_int) {
  my_stl::Multiset<int> s1;
  s1.insert(5);
  s1.insert(6);

  my_stl::Multiset<int> s2 = std::move(s1);

  EXPECT_EQ(0, (int)s1.size());
  EXPECT_EQ(2, (int)s2.size());
}

TEST_F(TestMultiset, Constructor_move_equal_double) {
  my_stl::Multiset<double> s1;
  s1.insert(-999.999212);
  s1.insert(0.000012);

  my_stl::Multiset<double> s2 = std::move(s1);

  EXPECT_EQ(true, s1.empty());
  EXPECT_DOUBLE_EQ(*s2.begin(), -999.999212);
  EXPECT_DOUBLE_EQ(*++s2.begin(), 0.000012);
  EXPECT_EQ(0, (int)s1.size());
  EXPECT_EQ(2, (int)s2.size());
}

TEST_F(TestMultiset, Constructor_move_equal_string) {
  my_stl::Multiset<std::string> s1;
  s1.insert("Hello, ");
  s1.insert("World!");

  my_stl::Multiset<std::string> s2 = std::move(s1);

  EXPECT_EQ(true, s1.empty());
  EXPECT_EQ(*s2.begin(), "Hello, ");
  EXPECT_EQ(*++s2.begin(), "World!");
  EXPECT_EQ(0, (int)s1.size());
  EXPECT_EQ(2, (int)s2.size());
}
