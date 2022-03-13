#include <vector>

using namespace std;

class Solution {
public:
    static const int MASK1 = 1 << 7;
    static const int MASK2 = (1 << 7) + (1 << 6);
    
    int getUtf8Num(int val) {
        if ((val & MASK1) == 0) {
            return 1;
        }

        int num = 0, maskTmp = MASK1;
        while ((val & maskTmp) != 0) {
            if (++num > 4) return -1;
            maskTmp >>= 1;
        }
        return num >= 2 ? num : -1;
    }

    bool validUtf8(vector<int>& data) {
        int len = data.size();
        int index = 0;
        while (index < len) {
            int val = data[index];
            int utf8Num = getUtf8Num(val);
            if (utf8Num < 0 || index + utf8Num > len) return false;
            for (int i = 1; i < utf8Num; ++i) {
                if ((data[index + i] & MASK2) != MASK1) {
                    return false;
                }
            }
            index += utf8Num;
        }

        return true;
    }
};

int main(void) {
    vector<int> data = {197, 130, 1};
    Solution solution;
    bool ans = solution.validUtf8(data);
    return 0;
}