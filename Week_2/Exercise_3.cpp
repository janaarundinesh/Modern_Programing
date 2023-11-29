#include <iostream>

using namespace std;

//Draw Saltire:

bool Saltire(int size);

int main() {
    int size;

	while (true)
	{
		cout << "Size : ";
    	cin >> size;
    	bool result = Saltire(size);
		if (result == false)
		{
			break;
		}
	}

    return 0;
};

bool Saltire(int size) 
{
	char temp = 'y';
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j == i || j == size - i - 1) 
			{
                cout << "*";
            } else 
			{
                cout << " ";
            }
        }
        cout << endl;
    }
	cout << "Once more (y/n)? " ;
	cin >> temp;
	if (temp == 'y')
	{
		return true;
	}else if (temp == 'n')
	{
		return false;
	}
	else
	{
		cout << "Invalid Input!" << endl;
		return true;
	}

};
