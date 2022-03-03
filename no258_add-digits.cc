using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }

    int addDigits2(int num) {
        return (num - 1) % 9 + 1;
    }
};

int main(void) {
    Solution solution;
    int ans = solution.addDigits(138);
    ans = solution.addDigits2(138);
    return 0;
}