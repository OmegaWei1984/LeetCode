#include <gtest/gtest.h>

class Solution {
public:
    int doSomething(void) {
        return 0;
    }
};

TEST(isValid, isValid_1)
{
    Solution s;
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
