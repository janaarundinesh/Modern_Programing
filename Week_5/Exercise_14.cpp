#include<iostream>
#include<string>

using namespace std;

class Car
{
private:
    string type;
    double mileage;

public:
    Car(string Type = "unknown", double Mileage = 0) 
        : type(Type), mileage(Mileage) {} //Constructor

    void drive(double distance);
    void tow(double distance); // towed car
    string getType();
    double getMileage();
    void print();
};

void Car::drive(double distance)
{
    // Update mileage for driving
    mileage += distance;
}

void Car::tow(double distance)
{
    // Update mileage for towing
    mileage += distance;
}

string Car::getType()
{
    return type;
}

double Car::getMileage()
{
    return mileage;
}

void Car::print()
{
    cout << "Type: " << type << ", Mileage: " << mileage << " miles" << endl;
}

int main()
{
    // Create two cars and test all methods
    Car car1("Sedan", 10000);
    Car car2; // default values

    // Print initial details
    cout << "Car 1 - ";
    car1.print();
    cout << "Car 2 - ";
    car2.print();
    cout << endl;

    // Test drive and tow methods
    car1.drive(150);
    car2.tow(50);

    // Print details after driving and towing
    cout << "Car 1 - ";
    car1.print();
    cout << "Car 2 - ";
    car2.print();

    return 0;
}