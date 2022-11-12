#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size(), counter = 0;
        // for (int i = len - 1; i >= 0 ; --i) {
        //     if (s[i] == ' ' && counter == 0)
        //         continue;

        //     counter++;

        //     if (i >= 1 && s[i - 1] == ' ')
        //         return counter;
        // }

        int i = len - 1;
        while (i >= 0) {
            if (s[i] != ' ') {
                ++counter;
            }
            if (i - 1 >= 0 && s[i - 1] == ' ' && counter != 0) {
                return counter;
            }
            i--;
        }
        return counter;
    }
};

int main(void) {
    string s = "a";
    // string s = "   fly me   to   the moon  ";
    Solution solution;
    int ans = solution.lengthOfLastWord(s);
    cout << ans << endl;
    return 0;
} 