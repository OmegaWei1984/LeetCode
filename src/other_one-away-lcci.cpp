#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int firstSize = first.size();
        int secondSize = second.size();

        if ((firstSize == 1) && (secondSize == 1))
            return true;

        if (abs(firstSize - secondSize) >= 2)
            return false;

        int i = this->firstDiffIndex(first, second);
        if (i == -1)
            return true;
        
        vector<string> afterEdit = this->afterEdit();
    }
private:
    int firstDiffIndex(string& a, string& b) {
        for (int i = 0; i < a.size(); ++i)
            if (a[i] != b[i])
                return i;
        return -1;
    }

    vector<string> afterEdit() {}
};

int main(void) {
    Solution solution;
    string first = "pale";
    string second = "ple";
    bool ans = solution.oneEditAway(first, second);
    assert(ans);
    ans = solution.oneEditAway(second, first);
    assert(ans);
    first = "pales";
    second = "pal";
    ans = solution.oneEditAway(first, second);
    assert(!ans);
    ans = solution.oneEditAway(second, first);
    assert(!ans);

    return 0;
}
