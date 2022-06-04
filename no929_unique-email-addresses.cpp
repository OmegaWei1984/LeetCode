#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uset;
        for (string &email : emails) {
            string tmp;
            for (char letter : email) {
                if (letter == '@' || letter == '+') break;
                if (letter != '.')
                    tmp.push_back(letter);
            }
            tmp.append(email.substr(email.find('@')));
            uset.emplace(tmp);
        }
        return uset.size();
    }
};

int main(void) {
    Solution solution;
    vector<string> emails = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    int ans = solution.numUniqueEmails(emails);
}
