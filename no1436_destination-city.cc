#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        set<string> beginnings ;
        for (auto path : paths) {
            beginnings.insert(path[0]);
        }

        for (auto path : paths) {
            if (beginnings.find(path[1]) == beginnings.end()) {
                return path[1];
            }
        }

        return "";
    }
};

int main(void)
{
    vector<vector<string>> paths = {{"qMTSlfgZlC", "ePvzZaqLXj"}, {"xKhZXfuBeC", "TtnllZpKKg"}, {"ePvzZaqLXj", "sxrvXFcqgG"}, {"sxrvXFcqgG", "xKhZXfuBeC"}, {"TtnllZpKKg", "OAxMijOZgW"}};

    Solution solution;
    string res = solution.destCity(paths);
    cout << res << endl;

    return 0;
}