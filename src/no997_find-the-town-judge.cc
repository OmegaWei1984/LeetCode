#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findJudge1(int n, vector<vector<int>>& trust) {
        if (trust.size() == 0 && n == 1) return 1;
        set<int> a, b, c;
        vector<int> trusted(n, 0);
        for (vector<int> &townspeople : trust) {
            a.insert(townspeople[0]);
            b.insert(townspeople[1]);
            ++trusted[townspeople[1] - 1];
        }
        
        set_difference(b.cbegin(), b.cend(), a.cbegin(), a.cend(), inserter(c, c.end()));
        int result = *c.begin();
        return result != 0 && trusted[result - 1] == n - 1 ? result : -1;
    }

    int findJudge2(int n, vector<vector<int>>& trust) {
        if (trust.size() == 0 && n == 1) return 1;
        vector<int> out(n + 1), in(n + 1);
        for (vector<int> &townspeople : trust) {
            ++out[townspeople[0]];
            ++in[townspeople[1]];
        }

        for (int i = 1; i < n + 1; ++i) {
            if (out[i] == 0 && in[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }

};

int main(void) {
    int n = 4;
    vector<vector<int>> trust = {{1,3},{1,4},{2,3},{2,4},{4,3}};
    Solution solution;
    int answer = solution.findJudge2(n, trust);
    return 0;
}