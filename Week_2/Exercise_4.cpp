#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void reversed_num(int number);

int main() {
    int number;
    while (true) {
        cout << "Enter a number >= 10 : ";
        cin >> number;
        if (number >= 10) {
            reversed_num(number);
            break;
        }
    }
    return 0;
}

void reversed_num(int number) {
    string numberString = to_string(number);
    reverse(numberString.begin(), numberString.end());

    cout << "Reversed number: " << numberString << endl;
}
