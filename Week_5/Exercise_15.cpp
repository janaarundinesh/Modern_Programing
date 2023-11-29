#include<iostream>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

class Date {
private:
    year y;
    month m;
    day d;

public:
    // Constructor
    Date(year y, month m, day d) : y(y), m(m), d(d) {}

    // Public getter methods
    year getYear() const {
        return y;
    }

    month getMonth() const {
        return m;
    }

    day getDay() const {
        return d;
    }

    // Operator overloads
    bool operator==(const Date& other) const {
        return y == other.y && m == other.m && d == other.d;
    }

    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

    int operator-(const Date& other) const {
        // Compute the difference in days between *this and other
        days diff = sys_days{y / m / d} - sys_days{other.y / other.m / other.d};
        return diff.count();
    }
};

// Implement the public methods outside the class
year Date::getYear() const {
    return y;
}

month Date::getMonth() const {
    return m;
}

day Date::getDay() const {
    return d;
}

int main() {
    Date d1{year{2023}, month{3}, day{23}};
    cout << (d1 == d1) << endl; // Testing operator==
    cout << (d1 != d1) << endl; // Testing operator!=

    Date d2{year{2023}, month{3}, day{23}};
    cout << (d1 == d2) << endl; // Testing operator==
    cout << (d1 != d2) << endl; // Testing operator!=

    cout << (d1 - d2) << endl; // Testing operator-

    // Accessing individual components using public methods
    cout << "Year: " << d1.getYear().count() << endl;
    cout << "Month: " << static_cast<unsigned>(d1.getMonth()) << endl;
    cout << "Day: " << static_cast<unsigned>(d1.getDay()) << endl;

    return 0;
}
