#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> days = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        return isLeapYear(year) && month > 2 ? days[month - 1] + day + 1 : days[month - 1] + day;
    }

    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

int main(void) {
    Solution solution;
    cout << solution.dayOfYear("2008-12-31") << endl;
    cout << solution.dayOfYear("2008-01-31") << endl;
    cout << solution.dayOfYear("2016-02-09") << endl;
    cout << boolalpha << solution.isLeapYear(2008) << endl;
    cout << boolalpha << solution.isLeapYear(2009) << endl;
    return 0;
}