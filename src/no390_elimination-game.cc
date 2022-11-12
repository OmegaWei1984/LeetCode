#include<iostream>

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        int a = 1, k = 0, c = n, s = 1;
        while(c > 1) {
            if (k % 2 == 0) {
                a += s;
            } else {
                a = (c % 2 == 0) ? a : a + s;
            }
            ++k;
            c /= 2;
            s *= 2;
        }

        return a;
    }
};

int main(void) {
    Solution solution;
    cout << solution.lastRemaining(10) << endl;
    return 0;
}