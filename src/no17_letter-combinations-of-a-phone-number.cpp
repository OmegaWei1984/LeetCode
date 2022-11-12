// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    unordered_map<char, vector<char>> dig2num = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}};
    void backtrack(vector<string> &result, string &digits, int index, string &curr)
    {
        if (index == digits.size()) {
            result.push_back(curr);
        } else {
            char digit = digits[index];
            const vector<char>& letters = dig2num.at(digit);
            for (const char& letter : letters) {
                curr.push_back(letter);
                backtrack(result, digits, index + 1, curr);
                curr.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if (digits.empty())
        {
            return result;
        }
        string curr;
        backtrack(result, digits, 0, curr);
        return result;
    }
};

int main(void)
{
    string digits = "23";
    Solution solution;
    vector<string> ans = solution.letterCombinations(digits);
    return 0;
}
