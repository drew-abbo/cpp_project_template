#include <gtest/gtest.h>

TEST(TestSuiteName, TestName)
{
    EXPECT_EQ(7 * 6, 42) << "These numbers should match";
}
