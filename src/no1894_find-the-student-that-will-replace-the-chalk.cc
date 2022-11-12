#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(chalk.begin(), chalk.end(), 0);

        long long surplus = 0;
        surplus = k % sum;

        int i = -1;
        while(surplus > chalk[++i]) {
            surplus -= chalk[i];
        }

        return i;
    }
};

int main(void) {
    Solution solution;
    vector<int> chalk = {3, 4, 1, 2};
    int k = 25;
    int no = solution.chalkReplacer(chalk, k);
    cout << no << endl;
    return 0;
}