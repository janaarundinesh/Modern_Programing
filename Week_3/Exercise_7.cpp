#include <iostream>
#include <array>

using namespace std;

void reset(int n, int* cnt);
void print(int n, int* cnt);
bool isNull(int n, int* cnt);
void increment(int base, int n, int* cnt);

/* Main function */
int main() {
    int z[10];
    int b, n;
    cout << "base (2, ..., 10): ";
    cin >> b;
    cout << "number of digits of the counter (1, ..., 10): ";
    cin >> n;

    if ((b >= 2 && b <= 10) && (n >= 1 && n <= 10)) {
        reset(n, z);
        print(n, z);
        do {
            increment(b, n, z);
        } while (!isNull(n, z));
    } else {
        cerr << "Invalid Value for base or counter!" << endl;
    }

    return 0;
}
/* Reset counter array */
void reset(int n, int* cnt) {
    for (int i = 0; i < n; ++i) {
        cnt[i] = 0;
    }
}

/*Printing count array elements*/
void print(int n, int* cnt) {
    for (int i = 0; i < n; ++i) {
        cout << " " << cnt[i];
    }
    cout << endl;
}

/* Return true if all digits are zero or false otherwise*/
bool isNull(int n, int* cnt) {
    for (int i = 0; i < n; ++i) {
        if (cnt[i] != 0) {
            return false;
        }
    }
    return true;
}

/* Increment counter by one and carry over to next digit if necessary.*/
void increment(int base, int n, int* cnt) {
    int k = n - 1;
    while (k >= 0 && cnt[k] == base - 1) {
        cnt[k] = 0;
        k--;
    }
    if (k >= 0) {
        cnt[k]++;
    }
    print(n, cnt);
}