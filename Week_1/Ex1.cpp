/* Compile Line = g++ -Wall -std=c++11 Ex1.cpp -o Ex1 -lstdc++ */

#include <iostream>
#include <vector>
#include <cstdlib> // for atoi
using namespace std;

vector<int> Insertion_sort(vector<int> arr, int n);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <n> <element1> <element2> ... <elementN>\n";
        return 1;
    }

    int n = atoi(argv[1]);
    vector<int> arr(n);

    if (argc != n + 2) {
        cerr << "Invalid number of elements provided. Expected " << n << " elements.\n";
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 2]);
    }

    arr = Insertion_sort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

vector<int> Insertion_sort(vector<int> arr, int n) {
    for (int i = 1; i < n; i++) {
        int v = arr[i];
        int j = i;
        while (j > 0 && v < arr[j - 1]) {
            arr[j] = arr[j - 1];
            j = j - 1;
        }
        arr[j] = v;
    }
    return arr;
}
