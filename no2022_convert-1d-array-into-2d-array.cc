#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result;
        size_t len = original.size();
        if (len > m * n ) return result; 

        for (auto it = original.begin(); it != original.end(); it += n)
            result.emplace_back(it, it + n);

        return result;
    }
};

int main(void) {
    int m = 2, n = 2;
    vector<int> original = {1, 2, 3, 4}; 
    Solution solution;
    solution.construct2DArray(original, m, n);
    return 0;
}