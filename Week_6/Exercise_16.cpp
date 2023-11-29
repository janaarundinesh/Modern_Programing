#include<iostream>
#include<cmath>

using namespace std;

class Angle
{
private:
    int degrees;
    int minutes;
    double seconds;

public:
    // Constructor
    Angle(int d = 0, int m = 0, double s = 0.0)
    {
        degrees = d;
        minutes = m;
        seconds = s;
    }

    // Setter
    void set(int d, int m, double s);

    // Getter
    double getAsDegrees() const;

    // Addition of two angles
    Angle operator+(const Angle& other) const;

    // Output stream operator
    friend ostream& operator<<(ostream& os, const Angle& angle);

    // Input stream operator
    friend istream& operator>>(istream& is, Angle& angle);

    // Conversion to radian
    double toRadian() const;

    // Normalize angle
    void normalize();
};

// Implementation of member functions

void Angle::set(int d, int m, double s)
{
    degrees = d;
    minutes = m;
    seconds = s;
}

double Angle::getAsDegrees() const
{
    return degrees + minutes / 60.0 + seconds / 3600.0;
}

Angle Angle::operator+(const Angle& other) const
{
    int totalDegrees = degrees + other.degrees;
    int totalMinutes = minutes + other.minutes;
    double totalSeconds = seconds + other.seconds;

    if (totalSeconds >= 60.0)
    {
        totalSeconds -= 60.0;
        totalMinutes++;
    }

    if (totalMinutes >= 60)
    {
        totalMinutes -= 60;
        totalDegrees++;
    }

    return Angle(totalDegrees, totalMinutes, totalSeconds);
}

ostream& operator<<(ostream& os, const Angle& angle)
{
    os << angle.degrees << "°" << angle.minutes << "'" << angle.seconds << "''";
    return os;
}

istream& operator>>(istream& is, Angle& angle)
{
    is >> angle.degrees >> angle.minutes >> angle.seconds;
    return is;
}

double Angle::toRadian() const
{
    return getAsDegrees() * (M_PI / 180.0);
}

void Angle::normalize()
{
    while (seconds >= 60.0)
    {
        seconds -= 60.0;
        minutes++;
    }

    while (minutes >= 60)
    {
        minutes -= 60;
        degrees++;
    }
}

int main()
{
    // Test constructor
    Angle angle1(45, 30, 15.5);
    cout << "Angle 1: " << angle1 << endl;

    // Test setter
    Angle angle2;
    angle2.set(60, 45, 20.8);
    cout << "Angle 2 after set: " << angle2 << endl;

    // Test addition
    Angle angle3 = angle1 + angle2;
    cout << "Angle 3 (sum of Angle 1 and Angle 2): " << angle3 << endl;

    // Test getAsDegrees
    cout << "Angle 3 in degrees: " << angle3.getAsDegrees() << "°" << endl;

    // Test input stream operator
    Angle angle4;
    cout << "Enter an angle (degrees minutes seconds): ";
    cin >> angle4;
    cout << "You entered: " << angle4 << endl;

    // Test toRadian
    cout << "Angle 3 in radians: " << angle3.toRadian() << " radians" << endl;

    // Test normalize
    Angle angle5(370, 62, 83);
    cout << "Original angle: " << angle5 << endl;
    angle5.normalize();
    cout << "Normalized angle: " << angle5 << endl;

    return 0;
}
