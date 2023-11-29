#include<iostream>
#include<cmath>

using namespace std;

bool quad(double a, double b, double c, double& r1, double& r2);

int main()
{
    double a, b, c, r1, r2;
    bool result;
    cout << "Enter the Co-efficients a, b, c of a quadratic equation : ";
    cin >> a >> b >> c;
    result = quad(a, b, c, r1, r2);

    if(result == true)
    {
        cout << "Root 1 : " << r1 << endl;
        cout << "Root 2 : " << r2 << endl;
    }
    else
    {
        cerr << "The Given Quadratic Equation has 'Complex roots' ! " << endl;
    }

    return 0;
};

bool quad(double a, double b, double c, double& r1, double& r2)
{
    double discriminant = pow(b,2) - 4 * a * c;
    if (discriminant > 0) {
        r1 = (-b + sqrt(discriminant)) / (2 * a);
        r2 = (-b - sqrt(discriminant)) / (2 * a);
        return true;
    } else if (discriminant == 0) {
        r1 = -b / (2 * a);
        r2 = r1;
        return true;
    } else {
        return false;
    }
};