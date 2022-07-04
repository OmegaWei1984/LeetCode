// https://leetcode.cn/problems/minimum-absolute-difference/
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int min = INT_MAX;
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        int size = arr.size();
        for (int i = 0; i < size - 1; ++i) {
            int tmp = abs(arr[i] - arr[i + 1]);
            if (tmp <= min) {
                if (tmp < min) {
                    result.clear();
                    min = tmp;
                }
                vector<int> pair(2);
                pair[0] = arr[i];
                pair[1] = arr[i + 1];
                result.push_back(pair);
            }
        }
        return result;
    }
};

int main(void) {
    vector<int> arr = {4,2,1,3};
    Solution solution;
    vector<vector<int>> ans = solution.minimumAbsDifference(arr); 
    return 0;
}
