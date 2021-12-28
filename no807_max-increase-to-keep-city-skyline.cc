#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> rowMax = {};
        int ans = 0;
        int n = grid.size();
        for (int i = 0; i < grid.size(); ++i) {
            rowMax.push_back(*max_element(grid[i].begin(), grid[i].end()));
            for (int j = 0; j < grid[i].size(); ++j) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < rowMax.size(); ++i) {
            cout << rowMax[i] << endl;
        }
        vector<int> colMax;
        for (int i = 0; i < n; ++i) {
            vector<int> tmp = {};
            for(int j = 0; j < n; ++j) {
                tmp.push_back(grid[j][i]);
            }
            colMax.push_back(*max_element(tmp.begin(), tmp.end()));
        }
        // 分别求出行最大和列最大
        // result[m][n] = a[m][n] - min(rowMax[m], colMax[n])
        for (int i = 0; i < colMax.size(); ++i) {
            cout << colMax[i] << endl;
        }
        vector<vector<int>> result(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = min(colMax[j], rowMax[i]);
                int tmp = result[i][j];
                ans += tmp <= grid[i][j] ? 0 : tmp - grid[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        // cout << "ans: " << ans << endl;
        return ans;
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> grid = {
        {3, 0, 8, 4},
        {2, 4, 5, 7},
        {9, 2, 6, 3},
        {0, 3, 1, 0}
    };
    solution.maxIncreaseKeepingSkyline(grid);
    return 0;
}