#include "gt_multiset.h"

/*
  iterator begin()
*/

TEST_F(TestMultiset, Iterator_begin) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});

  my_stl::Multiset<int>::iterator it;
  it = s.begin();
  EXPECT_EQ(*it, -25);
}

TEST_F(TestMultiset, Const_iterator_begin) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});

  my_stl::Multiset<int>::const_iterator cit;
  cit = s.begin();
  EXPECT_EQ(*cit, -25);
}

/*
  iterator end()
*/

TEST_F(TestMultiset, Iterator_end) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});

  my_stl::Multiset<int>::iterator it;
  it = s.end();
  EXPECT_EQ(*it, 0);
}

TEST_F(TestMultiset, Const_iterator_end) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});

  my_stl::Multiset<int>::const_iterator it;
  it = s.end();
  EXPECT_EQ(*it, 0);
}

/* Iterator forward (postfix increment)*/
TEST_F(TestMultiset, Iterator_postfix_increment) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});

  my_stl::Multiset<int>::iterator it = s.begin();
  my_stl::Multiset<int>::iterator it2 = s.begin();
  for (; it2 != s.end();) {
    it++;
    it2++;
    EXPECT_EQ(*it, *it2);
  }
}

TEST_F(TestMultiset, Const_iterator_postfix_increment) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});

  my_stl::Multiset<int>::const_iterator it = s.begin();
  my_stl::Multiset<int>::const_iterator it2 = s.begin();
  for (; it2 != s.end();) {
    it++;
    it2++;
    EXPECT_EQ(*it, *it2);
  }
}

/* Iterator forward (prefix increment)*/
TEST_F(TestMultiset, Iterator_prefix_increment) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});

  my_stl::Multiset<int>::iterator it = s.begin();
  my_stl::Multiset<int>::iterator it2 = s.begin();
  for (; it2 != s.end();) {
    ++it;
    ++it2;
    EXPECT_EQ(*it, *it2);
  }
}

TEST_F(TestMultiset, Const_iterator_prefix_increment) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});

  my_stl::Multiset<int>::const_iterator it = s.begin();
  my_stl::Multiset<int>::const_iterator it2 = s.begin();
  for (; it2 != s.end();) {
    ++it;
    ++it2;
    EXPECT_EQ(*it, *it2);
  }
}

/* Iterator backward (postfix decrement)*/
TEST_F(TestMultiset, Iterator_postfix_decrement) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});

  my_stl::Multiset<int>::iterator it = s.end();
  my_stl::Multiset<int>::iterator it2 = s.end();
  for (; it2 != s.end();) {
    it--;
    it2--;
    EXPECT_EQ(*it, *it2);
  }
}

TEST_F(TestMultiset, Const_iterator_postfix_decrement) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});

  my_stl::Multiset<int>::const_iterator it = s.end();
  my_stl::Multiset<int>::const_iterator it2 = s.end();
  for (; it2 != s.end();) {
    it--;
    it2--;
    EXPECT_EQ(*it, *it2);
  }
}

/* Iterator backward (prefix decrement)*/
TEST_F(TestMultiset, Iterator_prefix_decrement) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});

  my_stl::Multiset<int>::iterator it = s.end();
  my_stl::Multiset<int>::iterator it2 = s.end();
  for (; it2 != s.end();) {
    --it;
    --it2;
    EXPECT_EQ(*it, *it2);
  }
}

TEST_F(TestMultiset, Const_iterator_prefix_decrement) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});

  my_stl::Multiset<int>::const_iterator it = s.end();
  my_stl::Multiset<int>::const_iterator it2 = s.end();
  for (; it2 != s.end();) {
    --it;
    --it2;
    EXPECT_EQ(*it, *it2);
  }
}

/* Iterator compare equal*/
TEST_F(TestMultiset, Iterator_compare_equal) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});

  my_stl::Multiset<int>::iterator it = s.begin();
  my_stl::Multiset<int>::iterator it2 = s.begin();
  for (; it2 != s.end(); ++it, ++it2) {
    EXPECT_EQ((it == it2), true);
  }
}

TEST_F(TestMultiset, Const_iterator_compare_equal) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});

  my_stl::Multiset<int>::const_iterator it = s.begin();
  my_stl::Multiset<int>::const_iterator it2 = s.begin();
  for (; it2 != s.end(); ++it, ++it2) {
    EXPECT_EQ((it == it2), true);
  }
}

/* Iterator compare not equal*/
TEST_F(TestMultiset, Iterator_compare_not_equal) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});

  my_stl::Multiset<int>::iterator it = s.begin();
  my_stl::Multiset<int>::iterator it2 = s.end();
  for (; it2 != s.end(); ++it, --it2) {
    EXPECT_EQ((it != it2), true);
  }
}

TEST_F(TestMultiset, Const_iterator_compare_not_equal) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});

  my_stl::Multiset<int>::const_iterator it = s.begin();
  my_stl::Multiset<int>::const_iterator it2 = s.end();
  for (; it2 != s.end(); ++it, --it2) {
    EXPECT_EQ((it != it2), true);
  }
}

/* Iterator  operator* Get ref*/
TEST_F(TestMultiset, Iterator_get_ptr) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});
  my_stl::Multiset<int>::iterator it = s.begin();

  EXPECT_EQ(*it, -25);
  EXPECT_EQ(*++it, -25);
  EXPECT_EQ(*++it, -7);
  EXPECT_EQ(*++it, -7);
  EXPECT_EQ(*++it, 0);
  EXPECT_EQ(*++it, 0);
  EXPECT_EQ(*++it, 1);
  EXPECT_EQ(*++it, 1);
  EXPECT_EQ(*++it, 1);
  EXPECT_EQ(*++it, 4);
  EXPECT_EQ(*++it, 9);
  EXPECT_EQ(*++it, 38);
}

TEST_F(TestMultiset, Const_iterator_get_ptr) {
  my_stl::Multiset<int> s;
  s.insert({9, 4, 1, -7, 0, -25, -25, 1, 38, 1, -7, 0});
  my_stl::Multiset<int>::const_iterator it = s.begin();

  EXPECT_EQ(*it, -25);
  EXPECT_EQ(*++it, -25);
  EXPECT_EQ(*++it, -7);
  EXPECT_EQ(*++it, -7);
  EXPECT_EQ(*++it, 0);
  EXPECT_EQ(*++it, 0);
  EXPECT_EQ(*++it, 1);
  EXPECT_EQ(*++it, 1);
  EXPECT_EQ(*++it, 1);
  EXPECT_EQ(*++it, 4);
  EXPECT_EQ(*++it, 9);
  EXPECT_EQ(*++it, 38);
}

/* Iterator  operator-> Get ptr */
TEST_F(TestMultiset, Iterator_get_ref) {
  my_stl::Tree<std::pair<int, char>, false> s;
  auto p1 = std::make_pair(1, 'a');
  auto p2 = std::make_pair(2, 'b');
  auto p3 = std::make_pair(3, 'c');

  s.insert({p1, p2, p3});

  my_stl::Tree<std::pair<int, char>, false>::iterator it = s.begin();
  EXPECT_EQ(it->first, 1);
  EXPECT_EQ(it->second, 'a');
  EXPECT_EQ(++it->first, 2);
  EXPECT_EQ(++it->second, 'b');
  EXPECT_EQ(++it->first, 3);
  EXPECT_EQ(++it->second, 'c');
}
