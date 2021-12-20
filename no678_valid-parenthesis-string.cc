#include <iostream>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;
        int len = s.length();

        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') {
                leftMin++;
                leftMax++;
            } else if (s[i] == ')') {
                leftMin = max(leftMin - 1, 0);
                if (--leftMax < 0) {
                    return false;
                }
            } else {
                leftMin= max(leftMin - 1, 0);
                leftMax++;
            }
        }

        return leftMin == 0;
    }
};

int main(void) {
    Solution solution;
    string s = "(*)";
    // string s = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";
    bool res = solution.checkValidString(s);
    cout << boolalpha << res << endl;
    return 0;
}