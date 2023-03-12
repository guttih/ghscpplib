#include <gtest/gtest.h>
#include <GhsCppLib/Version.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
  Version vv("1.2");
  vv.IncrementMinor();
  EXPECT_STREQ(vv.c_str(), "1.3");
}