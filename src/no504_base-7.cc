#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";

        string ans;
        bool isNegative = num < 0;
        num = abs(num);

        int tmp = 0;
        while (num != 0) {
            tmp = num % 7;
            num /= 7;
            ans.append(to_string(tmp));
        }

        if (isNegative) {
            ans.push_back('-');
        } 

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main(void) {
    Solution solution;
    string ans = solution.convertToBase7(100);
    ans = solution.convertToBase7(-7);
    return 0;
}