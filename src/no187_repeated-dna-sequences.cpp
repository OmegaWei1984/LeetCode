#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;

        unordered_map<string, int> map;
        int len = s.length();
        for (int i = 0; i <= len - 10; ++i) {
            string sub = s.substr(i, 10);
            if (++map[sub] == 2) {
                res.push_back(sub);
            }
        }

        return res;
    }
};

int main(void)
{
    string dna = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution solution;
    vector<string> ans = solution.findRepeatedDnaSequences(dna);
    for (const auto &s : ans)
    {
        cout << s << endl;
    }

    return 0;
}