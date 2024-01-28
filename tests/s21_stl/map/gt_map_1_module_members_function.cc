#include "gt_map.h"

/* Default constructor */
TEST_F(TestMap, Constructor_default_int) {
  s21::Map<int, int> m1;
  EXPECT_EQ(0, (int)m1.size());
}

TEST_F(TestMap, Constructor_default_double) {
  s21::Map<int, double> m1;
  EXPECT_EQ(0, (int)m1.size());
}

TEST_F(TestMap, Constructor_default_string) {
  s21::Map<int, std::string> m1;
  EXPECT_EQ(0, (int)m1.size());
}

/* With Allocator */
TEST_F(TestMap, Constructor_allocator_int) {
  s21::Map<int, int> m1;
  s21::Map<int, int>::allocator_type s_alloc;

  s_alloc = m1.get_allocator();

  s21::Map<int, int> m2(s_alloc);

  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.get_allocator(), m2.get_allocator());
}

TEST_F(TestMap, Constructor_allocator_double) {
  s21::Map<int, double> m1;
  s21::Map<int, double>::allocator_type s_alloc;

  s_alloc = m1.get_allocator();

  s21::Map<int, double> m2(s_alloc);

  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.get_allocator(), m2.get_allocator());
}

TEST_F(TestMap, Constructor_allocator_string) {
  s21::Map<int, std::string> m1;
  s21::Map<int, std::string>::allocator_type s_alloc;

  s_alloc = m1.get_allocator();

  s21::Map<int, std::string> m2(s_alloc);

  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.get_allocator(), m2.get_allocator());
}

/* Initializer list */
TEST_F(TestMap, Constructor_initializer_list_int) {
  auto ls1 = s21::make_mypair(1, 600);
  auto ls2 = s21::make_mypair(2, 700);
  auto ls3 = s21::make_mypair(3, 800);

  s21::Map<int, int> m1({ls1, ls2, ls3});

  std::map<int, int> m2({ls1, ls2, ls3});

  MAP_EXPECT_EQ(m1, m2);

  EXPECT_EQ(3, (int)m1.size());
}

TEST_F(TestMap, Constructor_initializer_list_equal_int) {
  auto ls1 = s21::make_mypair(1, 600);
  auto ls2 = s21::make_mypair(2, 700);
  auto ls3 = s21::make_mypair(3, 800);

  s21::Map<int, int> m1 = {ls1, ls2, ls3};

  std::map<int, int> m2 = {ls1, ls2, ls3};

  MAP_EXPECT_EQ(m1, m2);

  EXPECT_EQ(3, (int)m1.size());
}

/* Copy constructor*/
TEST_F(TestMap, Constructor_copy_int) {
  s21::Map<int, int> m1;
  m1.insert(1, 8);
  m1.insert(2, 9);

  s21::Map<int, int> m2(m1);

  EXPECT_EQ(*m1.begin(), *m2.begin());
  EXPECT_EQ(*m1.end(), *m2.end());
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.get_allocator(), m2.get_allocator());
}

TEST_F(TestMap, Constructor_copy_double) {
  s21::Map<int, double> m1;
  m1.insert(1, 0.129834);
  m1.insert(2, -1.000001);

  s21::Map<int, double> m2(m1);

  EXPECT_EQ(*m1.begin(), *m2.begin());
  EXPECT_EQ(*m1.end(), *m2.end());
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.get_allocator(), m2.get_allocator());
}

TEST_F(TestMap, Constructor_copy_string) {
  s21::Map<int, std::string> m1;
  m1.insert(1, "Hello, ");
  m1.insert(2, "World!");

  s21::Map<int, std::string> m2(m1);

  EXPECT_EQ(*m1.begin(), *m2.begin());
  EXPECT_EQ(*m1.end(), *m2.end());
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.get_allocator(), m2.get_allocator());
}

/* Copy equal */
TEST_F(TestMap, Constructor_copy_equal_int) {
  s21::Map<int, int> m1;
  m1.insert(1, 5);
  m1.insert(2, 6);

  s21::Map<int, int> m2 = m1;

  EXPECT_EQ(*m1.begin(), *m2.begin());
  EXPECT_EQ(*m1.end(), *m2.end());
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.get_allocator(), m2.get_allocator());
}

TEST_F(TestMap, Constructor_copy_equal_double) {
  s21::Map<int, double> m1;
  m1.insert(1, 0.129834);
  m1.insert(2, -1.000001);

  s21::Map<int, double> m2 = m1;

  EXPECT_EQ(*m1.begin(), *m2.begin());
  EXPECT_EQ(*m1.end(), *m2.end());
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.get_allocator(), m2.get_allocator());
}

TEST_F(TestMap, Constructor_copy_equal_string) {
  s21::Map<int, std::string> m1;
  m1.insert(1, "Hello, ");
  m1.insert(2, "World!");

  s21::Map<int, std::string> m2 = m1;

  EXPECT_EQ(*m1.begin(), *m2.begin());
  EXPECT_EQ(*m1.end(), *m2.end());
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.get_allocator(), m2.get_allocator());
}

/* Move constructor */
TEST_F(TestMap, Constructor_move_int) {
  s21::Map<int, int> m1;
  m1.insert(1, 5);
  m1.insert(2, 6);

  s21::Map<int, int> m2(std::move(m1));

  EXPECT_EQ(true, m1.empty());
  EXPECT_EQ((*m2.begin()).second, 5);
  EXPECT_EQ((*++m2.begin()).second, 6);
  EXPECT_EQ(0, (int)m1.size());
  EXPECT_EQ(2, (int)m2.size());
}

TEST_F(TestMap, Constructor_move_double) {
  s21::Map<int, double> m1;
  m1.insert(1, -999.999212);
  m1.insert(2, 0.000012);

  s21::Map<int, double> m2(std::move(m1));

  EXPECT_EQ(true, m1.empty());
  EXPECT_EQ((*m2.begin()).second, -999.999212);
  EXPECT_EQ((*++m2.begin()).second, 0.000012);
  EXPECT_EQ(0, (int)m1.size());
  EXPECT_EQ(2, (int)m2.size());
}

TEST_F(TestMap, Constructor_move_string) {
  s21::Map<int, std::string> m1;
  m1.insert(1, "Hello, ");
  m1.insert(2, "World!");

  s21::Map<int, std::string> m2(std::move(m1));

  EXPECT_EQ(true, m1.empty());
  EXPECT_EQ((*m2.begin()).second, "Hello, ");
  EXPECT_EQ((*++m2.begin()).second, "World!");
  EXPECT_EQ(0, (int)m1.size());
  EXPECT_EQ(2, (int)m2.size());
}

/* Move equal */
TEST_F(TestMap, Constructor_move_equal_int) {
  s21::Map<int, int> m1;
  m1.insert(1, 5);
  m1.insert(2, 6);

  s21::Map<int, int> m2 = std::move(m1);

  EXPECT_EQ(0, (int)m1.size());
  EXPECT_EQ(2, (int)m2.size());
}

TEST_F(TestMap, Constructor_move_equal_double) {
  s21::Map<int, double> m1;
  m1.insert(1, -999.999212);
  m1.insert(2, 0.000012);

  s21::Map<int, double> m2 = std::move(m1);

  EXPECT_EQ(true, m1.empty());
  EXPECT_EQ((*m2.begin()).second, -999.999212);
  EXPECT_EQ((*++m2.begin()).second, 0.000012);
  EXPECT_EQ(0, (int)m1.size());
  EXPECT_EQ(2, (int)m2.size());
}

TEST_F(TestMap, Constructor_move_equal_string) {
  s21::Map<int, std::string> m1;
  m1.insert(1, "Hello, ");
  m1.insert(2, "World!");

  s21::Map<int, std::string> m2 = std::move(m1);

  EXPECT_EQ(true, m1.empty());
  EXPECT_EQ((*m2.begin()).second, "Hello, ");
  EXPECT_EQ((*++m2.begin()).second, "World!");
  EXPECT_EQ(0, (int)m1.size());
  EXPECT_EQ(2, (int)m2.size());
}
