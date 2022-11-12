// 200. 岛屿数量 https://leetcode.cn/problems/number-of-islands/

#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& grid, const int& rowSize, const int& colSize, int row, int col) {
        grid[row][col] = '0';

        if (row - 1 >= 0 && grid[row - 1][col] == '1') {
            dfs(grid, rowSize, colSize, row - 1, col);
        }
        if (row + 1 < rowSize && grid[row + 1][col] == '1') {
            dfs(grid, rowSize, colSize, row + 1, col);
        }
        if (col - 1 >= 0 && grid[row][col - 1] == '1') {
            dfs(grid, rowSize, colSize, row, col - 1);
        }
        if (col + 1 < colSize && grid[row][col + 1] == '1') {
            dfs(grid, rowSize, colSize, row, col + 1);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rowSize = grid.size();
        if (rowSize == 0) return 0;
        int colSize = grid[0].size();

        int result = 0;
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (grid[i][j] == '1') {
                    ++result;
                    dfs(grid, rowSize, colSize, i, j);
                }
            }
        }

        return result;
    }
};

class Solution2 {
private:
    void bfs(vector<vector<char>>& grid, const int& rowSize, const int& colSize, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty()) {
            pair<int, int> f = q.front();
            q.pop();
            int r = f.first;
            int c = f.second;
            if (r - 1 >= 0 && grid[r - 1][c] == '1') {
                q.push({r - 1, c});
                grid[r - 1][c] = '0';
            }
            if (r + 1 < rowSize && grid[r + 1][c] == '1') {
                q.push({r + 1, c});
                grid[r + 1][c] = '0';
            }
            if (c - 1 >= 0 && grid[r][c - 1] == '1') {
                q.push({r, c - 1});
                grid[r][c - 1] = '0';
            }
            if (c + 1 < colSize && grid[r][c + 1] == '1') {
                q.push({r, c + 1});
                grid[r][c + 1] = '0';
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rowSize = grid.size();
        if (rowSize == 0) return 0;
        int colSize = grid[0].size();

        int result = 0;
        for (int row = 0; row < rowSize; ++row) {
            for (int col = 0; col < colSize; ++col) {
                if (grid[row][col] == '1') {
                    ++result;
                    grid[row][col] = '0';
                    bfs(grid, rowSize, colSize, row, col);
                }
            }
        }

        return result;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    vector<vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    Solution solution;
    int ans = solution.numIslands(grid);
    int ans2 = solution.numIslands(grid2);


    vector<vector<char>> grid3 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    vector<vector<char>> grid4 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    Solution2 solution2;
    int ans3 = solution2.numIslands(grid3);
    int ans4 = solution2.numIslands(grid4);

    return 0;
}
