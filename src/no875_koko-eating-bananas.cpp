#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int k = high;
        while (low < high) {
            int speed = (high - low) / 2 + low;
            long time = 0;
            for_each(piles.begin(), piles.end(), [&](const int &pile){
                time += (pile + speed - 1) / speed;
            });
            if (time <= h) {
                k = speed;
                high = speed;
            } else {
                low = speed + 1;
            }
        }
        return k;
    }
};

int main(void) {
    Solution solution;
    vector<int> piles = {3,6,7,11};
    int h = 8;
    int ans = solution.minEatingSpeed(piles, h);
    return 0;
}
