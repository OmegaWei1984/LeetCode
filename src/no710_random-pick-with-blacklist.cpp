// https://leetcode.cn/problems/random-pick-with-blacklist/

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <random>

using namespace std;

class Solution {
private:
    int bound;
    unordered_map<int, int> map;
    mt19937 gen{random_device{}()};
public:
    Solution(int n, vector<int>& blacklist) {
        int m = blacklist.size();
        bound = n - m;
        unordered_set<int> blacks;
        for (int black : blacklist)
            if (black >= bound)
                blacks.emplace(black);
        int white = bound;
        for (int black : blacklist) {
            if (black < bound) {
                while (blacks.count(white))
                    ++white;
                map[black] = white++;
            }
        }
    }
    
    int pick() {
        uniform_int_distribution<int> dis(0, bound - 1);
        int num = dis(gen);
        return map.count(num) ? map[num] : num;
    }
};

int main(void) {
    vector<int> blacklist = {2, 3, 5};
    Solution solution(7, blacklist);
    int ans = solution.pick();
    return 0;
}