#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Date {
public:
    using year = chrono::year;
    using month = chrono::month;
    using day = chrono::day;
    using days = chrono::duration<int>;

    Date(year y, month m, day d) : y(y), m(m), d(d) {}

    year getYear() const;
    month getMonth() const;
    day getDay() const;

    bool operator==(const Date& other) const;
    int operator-(const Date& other) const;

private:
    year y;
    month m;
    day d;
};

Date::year Date::getYear() const {
    return y;
}

Date::month Date::getMonth() const {
    return m;
}

Date::day Date::getDay() const {
    return d;
}

bool Date::operator==(const Date& other) const {
    return y == other.y && m == other.m && d == other.d;
}

int Date::operator-(const Date& other) const {
    days diff = sys_days{year_month_day{y, m, d}} - sys_days{year_month_day{other.y, other.m, other.d}};
    return diff.count();
}

int main() {
    Date d1{year{2023}, month{3}, day{23}};
    Date d2{year{2023}, month{3}, day{23}};

    cout << (d1 == d2) << endl; // Testing operator==
    cout << (d1 != d2) << endl; // Testing operator!=
    cout << (d1 - d2) << endl; // Testing operator-

    cout << "Year: " << static_cast<int>(d1.getYear()) << endl;
    cout << "Month: " << static_cast<unsigned>(d1.getMonth()) << endl;
    cout << "Day: " << static_cast<unsigned>(d1.getDay()) << endl;

    return 0;
}
