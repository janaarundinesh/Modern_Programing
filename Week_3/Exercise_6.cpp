#include<iostream>

using namespace std;

void SumOfDigits(int number, int& result);

int main()
{
    int number , result = 0;
    cout << "Enter a Number : ";
    cin >> number;
    SumOfDigits(number, result);
    cout << "Sum of the Digits of  "<< number << " is : " << result << endl;;
    return 0;
};

void SumOfDigits(int number, int& result)
{
    int temp;
    if(number > 0)
    {
        temp = number % 10;
        result += temp;
        number = number / 10;
        SumOfDigits(number, result);
    }
};