#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (auto &word : words) {
            if (isMatch(word, pattern) && isMatch(pattern, word)) {
                ans.emplace_back(word);
            }
        }
        return ans;
    }

    bool isMatch(string &word, string pattern) {
        unordered_map<char, char> map;
        for (int i = 0; i < word.length(); ++i) {
            if (map.count(word[i]) == 0) {
                map[word[i]] = pattern[i];
            } else if (map[word[i]] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
};

int main(void) {
    Solution solution;
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    vector<string> ans = solution.findAndReplacePattern(words, pattern);
    return 0;
}
