#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &&words, int k)
    {
        unordered_map<string, int> m;
        for (const auto &word : words)
        {
            m[word]++;
        }
        vector<string> res;
        for (const pair<string, int> &p : m)
        {
            res.push_back(p.first);
        }
        sort(res.begin(), res.end(), [&m](const string &a, const string &b) {
            if (m[a] > m[b]) {
                return true;
            } else if (m[a] == m[b]) {
                return a < b;
            } else {
                return false;
            } });
        res.erase(res.begin() + k, res.end());
        return res;
    }
};

int main(void)
{
    Solution solution;
    // vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    vector<string> res = solution.topKFrequent(
        {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"}, 4);
    return 0;
}
