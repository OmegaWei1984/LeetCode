#include <vector>

using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        if (n < 2)
        {
            return n;
        }
        int p = 0, q = 0, r = 1;
        for (int i = 2; i <= n; ++i)
        {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};

class Solution2
{
private:
    vector<vector<int>> matrixPow(vector<vector<int>> &matrix, int n)
    {
        vector<vector<int>> result = {{1, 0}, {0, 1}};
        while (n > 0)
        {
            if (n & 1)
            {
                result = matrixMulti(result, matrix);
            }
            n >>= 1;
            matrix = matrixMulti(matrix, matrix);
        }

        return result;
    }
    vector<vector<int>> matrixMulti(vector<vector<int>> &ma, vector<vector<int>> &mb)
    {
        vector<vector<int>> result = {{0, 0}, {0, 0}};
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                result[i][j] = ma[i][0] * mb[0][j] + ma[i][1] * mb[1][j];
            }
        }
        return result;
    }

public:
    int fib(int n)
    {
        if (n < 2)
        {
            return n;
        }
        vector<vector<int>> q = {{1, 1}, {1, 0}};
        vector<vector<int>> result = matrixPow(q, n - 1);

        return result[0][0];
    }
};

int main(void)
{
    int n = 4;
    Solution solution;
    int ans = solution.fib(n);

    Solution2 solution2;
    int ans2 = solution2.fib(n);
    return 0;
}
