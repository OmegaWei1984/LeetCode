// https://leetcode.cn/problems/generate-random-point-in-a-circle/

#include <vector>
#include <random>

using namespace std;

class Solution {
private:
    double r, xc, yc;
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
public:
    Solution(double radius, double x_center, double y_center):
        dis(-radius, radius), xc(x_center), yc(y_center), r(radius) {}
    
    vector<double> randPoint() {
        while (true) {
            double x = dis(gen);
            double y = dis(gen);
            if (x * x + y * y < r * r)
                return {xc + x, yc + y};
        }
    }
};

int main(void)
{
    Solution *obj = new Solution(1, 0, 0);
    vector<double> ans1 = obj->randPoint();
    vector<double> ans2 = obj->randPoint();
    vector<double> ans3 = obj->randPoint();
    vector<double> ans4 = obj->randPoint();
    return 0;
}