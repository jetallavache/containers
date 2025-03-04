#include "gt_map.h"

/*
    mapped_type& at(const key_type& key)
*/

TEST_F(TestMap, At_int) {
  my_stl::Map<int, int> m;
  m.insert(1, 2);
  m.insert(4, -3);
  m.insert(8, 34);
  m.insert(12, 0);

  EXPECT_EQ(m.at(1), 2);
  EXPECT_EQ(m.at(4), -3);
  EXPECT_EQ(m.at(8), 34);
  EXPECT_EQ(m.at(12), 0);

  try {
    EXPECT_EQ(m.at(0), 0);
    EXPECT_EQ(m.at(99), 0);
  } catch (std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }
}

TEST_F(TestMap, At_double) {
  my_stl::Map<int, double> m;
  m.insert(1, 1.12);
  m.insert(4, -3.00001);
  m.insert(8, 0.000221);
  m.insert(12, 43234.001);

  EXPECT_EQ(m.at(1), 1.12);
  EXPECT_EQ(m.at(4), -3.00001);
  EXPECT_EQ(m.at(8), 0.000221);
  EXPECT_EQ(m.at(12), 43234.001);

  try {
    EXPECT_EQ(m.at(0), 0);
    EXPECT_EQ(m.at(99), 0);
  } catch (std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }
}

TEST_F(TestMap, At_string) {
  my_stl::Map<int, std::string> m;
  m.insert(1, "hello");
  m.insert(4, "code21");
  m.insert(8, "");
  m.insert(12, "8765432qa");

  EXPECT_EQ(m.at(1), "hello");
  EXPECT_EQ(m.at(4), "code21");
  EXPECT_EQ(m.at(8), "");
  EXPECT_EQ(m.at(12), "8765432qa");

  try {
    EXPECT_EQ(m.at(0), "");
    EXPECT_EQ(m.at(99), "");
  } catch (std::out_of_range& e) {
    std::cerr << e.what() << std::endl;
  }
}

/*
    mapped_type& operator[](const key_type& key)
*/

TEST_F(TestMap, Access_operator_int) {
  my_stl::Map<int, int> m;
  m.insert(1, 2);
  m.insert(4, -3);
  m.insert(8, 34);
  m.insert(12, 0);

  EXPECT_EQ(m[1], 2);
  m[1] = 9;
  EXPECT_EQ(m.at(1), 9);

  EXPECT_EQ(m[4], -3);
  m[4] = -13;
  EXPECT_EQ(m.at(4), -13);

  EXPECT_EQ(m[8], 34);
  m[8] = 43;
  EXPECT_EQ(m.at(8), 43);

  EXPECT_EQ(m[12], 0);
  m[12] = 40;
  EXPECT_EQ(m.at(12), 40);

  EXPECT_EQ(m[32], 0);
  m[32] = 400;
  EXPECT_EQ(m.at(32), 400);
}
