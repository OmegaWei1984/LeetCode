#include <bit>
#include <bitset>

using namespace std;

class Solution {
public:
    bool isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) return false;
        }

        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            uint8_t tmp = (uint8_t)i;
            if (isPrime(popcount(tmp))) ++ans;
        }
        return ans;
    }

    int countPrimeSetBits2(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            uint8_t tmp = (uint8_t)i;
            if ((1 << popcount(tmp)) & 665772) ++ans;
        }

        return ans;
    }
};

int main(void) {
    Solution solution;
    solution.countPrimeSetBits(6, 10);
    solution.countPrimeSetBits2(6, 10);
    return 0;
}