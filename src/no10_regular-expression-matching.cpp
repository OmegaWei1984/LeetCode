#include <gtest/gtest.h>
#include "common.h"

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j)
        {
            if (i == 0)
            {
                return false;
            }
            if (p[j - 1] == '.')
            {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j - 1] == '*')
                {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1))
                    {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else
                {
                    if (matches(i, j))
                    {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};

TEST(matching, matching_a)
{
    Solution solution;

    string s = "aa";
    string p = "a";
    bool res1 = solution.isMatch(s, p);
    EXPECT_EQ(res1, false);
}

TEST(matching, matching_star)
{
    Solution solution;
    string s = "aa";
    string s2 = "aaaa";
    string s3 = "ab";
    string p = "a*";
    bool res1 = solution.isMatch(s, p);
    bool res2 = solution.isMatch(s2, p);
    bool res3 = solution.isMatch(s3, p);
    EXPECT_EQ(res1, true);
    EXPECT_EQ(res2, true);
    EXPECT_EQ(res3, false);
}

TEST(matching, matching_dotstar)
{
    Solution solution;
    string s = "ab";
    string s2 = "cccc";
    string p = ".*";
    bool res1 = solution.isMatch(s, p);
    bool res2 = solution.isMatch(s, p);
    EXPECT_EQ(res1, true);
    EXPECT_EQ(res2, true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
