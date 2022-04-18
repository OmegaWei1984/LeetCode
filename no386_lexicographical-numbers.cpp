#include <vector>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result(n);
        int number = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = number;
            if (number * 10 <= n)
                number *= 10;
            else {
                while (number % 10 == 9 || number + 1 > n) number /= 10;
                number++;
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<int> ans = solution.lexicalOrder(13);
    return 0;
}
