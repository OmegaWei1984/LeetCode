#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        bool is_not_space = false;
        int counter = 0;
        for (const char &c : s) {
            if (!is_not_space && c != ' ') {
                ++counter;
                is_not_space = true;
            } else if (c == ' ') {
                is_not_space = false;
            }
        }

        return counter;
    }
};

int main(void) {
    // string s = "hello world";
    string s = "Hello, my name is John";
    Solution solution;
    cout << solution.countSegments(s) << endl;
    return 0;
}