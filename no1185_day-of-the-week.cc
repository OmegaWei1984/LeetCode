#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string dayOfTheWeek(int day, int month, int year)
    {
        // 通过查询日历可知，1970 年 12 月 31 日是星期四，1972 年是第 1 个闰年、1968 年是第 0 个闰年
        int days = (year - 1970 - 1) * 365;
        if (year > 1972)
            days += (year - 1 - 1968) / 4;

        for (int i = 0; i < month - 1; ++i)
        {
            days += _day[i];
        }

        if ((year % 4 == 0 && year % 100 != 0) && month > 2)
            days += 1;

        days += day;

        return _week[days % 7];
    }

    string dayOfTheWeek2(int day, int month, int year)
    {
        if (month == 1 || month == 2)
        {
            month += 12;
            year -= 1;
        }
        // 基姆拉尔森计算公式
        int week = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
        return _week2[week];
    }

    string dayOfTheWeek3(int day, int month, int year)
    {
        if (month == 1 || month == 2)
        {
            month += 12;
            year -= 1;
        }

        // 蔡勒公式
        int century = year / 100;
        year %= 100;
        int week = year + year / 4 + century / 4 - 2 * century + ((26 * (month + 1)) / 10 + day - 1);
        week = (week % 7 + 7) % 7;

        return _week2[week];
    }

private:
    // const vector<string> _week = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
    const string _week[7] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
    const string _week2[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // const vector<int> _day = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    const int _day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
};

int main(void)
{
    int day = 29, month = 2, year = 2016;
    Solution solution;
    // string week = solution.dayOfTheWeek(day, month, year);
    // string week2 = solution.dayOfTheWeek2(day, month, year);
    string week3 = solution.dayOfTheWeek3(day, month, year);
    return 0;
}
