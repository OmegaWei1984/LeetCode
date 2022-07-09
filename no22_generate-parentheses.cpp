// https://leetcode.cn/problems/generate-parentheses/

#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> result;
    void generate(string &curr, int n) {
        if (n == curr.size()) {
            if (isValid(curr)) {
                result.push_back(curr);
            }
            return;
        }
        curr += '(';
        generate(curr, n);
        curr.pop_back();
        curr += ')';
        generate(curr, n);
        curr.pop_back();
    }

    bool isValid(const string& str) {
        int balance = 0;
        for(char c : str) {
            balance = c == '(' ? balance + 1 : balance - 1;
            if (balance < 0) {
                return false;
            }
        }
        return balance == 0;
    }
public:
    vector<string> generateParenthesis(int n) {
        string curr;
        generate(curr, n * 2);
        return result;
    }
};


class Solution2 {
private:
    void backstrack(vector<string>& result, string& curr, int open, int close, int n) {
        if (curr.size() == n * 2) {
            result.push_back(curr);
            return ;
        }
        if (open < n) {
            curr.push_back('(');
            backstrack(result, curr, open + 1, close, n);
            curr.pop_back();
        }
        if (close < open) {
            curr.push_back(')');
            backstrack(result, curr, open, close + 1, n);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        backstrack(result, curr, 0, 0, n);
        return result;
    }
};

int main(void) {
    int n = 3;
    Solution solution;
    vector<string> ans = solution.generateParenthesis(n);
    return 0;
}
