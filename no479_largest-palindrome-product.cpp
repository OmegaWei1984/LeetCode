#include <cmath>

using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;

        int upper = pow(10, n) - 1;  
        for (int leftHalf = upper; leftHalf > 0; --leftHalf) {
            long palindrome = leftHalf;
            for (int i = leftHalf; i > 0; i /= 10) {
                palindrome = palindrome * 10 + i % 10;
            }
            for (long i = upper; i * i >= palindrome; --i) {
                if (palindrome % i == 0) return palindrome % 1337;
            }
        }

        return 0;
    }
};

int main(void) {
    Solution solution;
    int ans = solution.largestPalindrome(2);
}
