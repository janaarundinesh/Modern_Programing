#include<iostream>
#include<random>

using namespace std;

void print_avg(int n , int* array_v);

int main()
{
    int* array_v;
    int n , m;
    cout << "Enter the values of 'n' , 'm' in natural number : ";
    cin >> n >> m ;
    if (n > 0 && m > 0)
    {
        // Allocate memory for dynamic array.
        array_v = new int[n];

        // Seed the random number generator with the current time
        srand(time(0));

        // Initialize the array with random values using rand
        for (int i = 0; i < n; i++)
        {
            array_v[i] = rand() % (m + 1);  // Generate a random number between 0 and m
        }
        print_avg(n , array_v);
        delete[] array_v; // memory deallocation.
    }
    else{
        cerr << "Invalid Number !";
    }
    return 0;
};

/* Function to calculate and print average */
void print_avg(int n , int* array_v)
{
    float result = 0; // Initialize result to 0
    if (n >= 10) // If there are at least 10 elements
    {
        for(int i = 0 ; i < 10 ; ++i) // Loop through the first 10 elements
        {
            result = result + array_v[i]; // Add current element to result
            cout << " " << array_v[i]; // Print current element
        }
        cout << endl; // Move to the next line
        cout << "Average of first ten elements is : " << result/10 << endl; // Print average of first 10 elements
    }
    else // If there are less than 10 elements
    {
        for(int i = 0 ; i < n ; ++i) // Loop through all elements
        {
            result = result + array_v[i]; // Add current element to result
            cout << " " << array_v[i]; // Print current element
        }
        cout << endl; // Move to the next line
        cout << "Average of elements in array is : " << result/n << endl; // Print average of all elements
    }
}