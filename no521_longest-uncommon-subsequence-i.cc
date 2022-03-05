#include <string>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a != b ? max(a.size(), b.size()) : -1;
    }
};

int main(void) {
    Solution solution;
    int ans = solution.findLUSlength("abc", "bacab"); 
    return 0;
}
