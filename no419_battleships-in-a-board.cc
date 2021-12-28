#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int result = 0;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X') {
                    // // solution 1
                    // ++result;
                    // for (int k = i + 1; k < m && board[k][j] == 'X'; ++k)
                    //     board[k][j] = '.';
                    // for (int k = j + 1; k < n && board[i][k] == 'X'; ++k)
                    //     board[i][k] = '.';
                    // solution 2
                    if (i - 1 >= 0 && board[i - 1][j] == 'X') 
                        continue;
                    if (j - 1 >= 0 && board[i][j - 1] == 'X') 
                        continue;
                    ++result;
                }
            }
        }        
        return result;
    }
};

int main(void) {
    vector<vector<char>> board = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
    Solution solution;
    int answer =  solution.countBattleships(board);
    cout << "answer: " << answer << endl;
    return 0;
}