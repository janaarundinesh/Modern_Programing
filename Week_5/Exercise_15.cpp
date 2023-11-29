#include <iostream>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = month = 1;
        year = 1970;
    }

    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setDate(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    void print() const
    {
        cout << day << '.' << month << '.' << year << endl;
    }

    int dayInYear() const;
};

int Date::dayInYear() const
{
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int result = day;

    for (int i = 1; i < month; ++i)
    {
        result += daysInMonth[i];
    }

    if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        // Leap year: add one more day for February
        ++result;
    }

    return result;
}

int main()
{
    const Date d1{1, 3, 2020}; // Leap year
    const Date d2{2, 9, 2004}; // Non-leap year

    cout << "Date 1: ";
    d1.print();
    cout << "Day in the year (Leap year): " << d1.dayInYear() << endl;

    cout << "\nDate 2: ";
    d2.print();
    cout << "Day in the year (Non-leap year): " << d2.dayInYear() << endl;

    return 0;
}
