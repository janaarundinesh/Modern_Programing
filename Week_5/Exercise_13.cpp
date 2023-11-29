#include <iostream>
#include <string>

using namespace std;

class Country
{
private:
    string name;
    string capital;
    int areaKm2;
    int population;

public:
    Country(string Name, string Capital, int Area, int Population)
        : name(Name), capital(Capital), areaKm2(Area), population(Population) {}

    void updatePopulation(int newValue);
    double getPopulationDensity() const; 
    void print() const;                  
};

void Country::updatePopulation(int newValue)
{
    if (newValue >= 0)
    {
        population = newValue;
    }
    else
    {
        cerr << "Invalid Population Value!" << endl;
    }
}

double Country::getPopulationDensity() const
{
    return static_cast<double>(population) / areaKm2; 
}

void Country::print() const
{
    cout << "Country: " << name << endl;
    cout << "Capital: " << capital << endl;
    cout << "Area: " << areaKm2 << " km^2" << endl;
    cout << "Population: " << population << endl;
    cout << "Population Density: " << getPopulationDensity() << " people/km^2" << endl;
}

int main()
{
    // Create a country object with the given values.
    Country myCountry("India", "Delhi",  3287263, 1428627663);

    // Calls every method:
    myCountry.print();
    cout << endl;
    myCountry.updatePopulation(1528627663);
    myCountry.print();

    cout << endl;
    myCountry.updatePopulation(-1628627663);
    myCountry.print();

    return 0;
}
