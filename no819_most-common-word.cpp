#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string result, buffer;
        unordered_map<string, int> counters;
        paragraph.push_back(' ');
        for_each(paragraph.begin(), paragraph.end(), [&](char c){
            if (isalpha(c) != 0) {
                buffer.push_back(c);
            } else if (buffer.size() != 0){
                transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);
                counters[buffer]++;
                buffer.clear();
            }
        });
        int maximum = 0;
        for (const auto& [key, value] : counters) {
            if (value > maximum && find(banned.begin(), banned.end(), key) == banned.end()) {
                maximum = value;
                result = key;
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    // string paragraph = "Bob";
    vector<string> banned = {"hit"};
    // vector<string> banned = {};
    string ans = solution.mostCommonWord(paragraph, banned);

    return 0;
}
