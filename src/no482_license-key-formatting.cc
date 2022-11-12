#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        string formatted;
        int counter = 0;
        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (s[i] != '-')
            {
                formatted.push_back(toupper(s[i]));
                ++counter;
                if (counter == k) {
                    counter = 0;
                    formatted.push_back('-');
                }
            }
        }

        if (formatted.back() == '-')
            formatted.pop_back();

        reverse(formatted.begin(), formatted.end());

        return formatted;
    }
};

int main(void)
{
    // string S = "2-5g-3-J";
    // int K = 2;

    string S = "5F3Z-2e-9-w";
    int K = 4;

    // string S = "a-a-a-a-";
    // int K = 1;

    // string S = "2-5g-3-J";
    // int K = 2;

    Solution solution;
    cout << solution.licenseKeyFormatting(S, K) << endl;
    return 0;
}