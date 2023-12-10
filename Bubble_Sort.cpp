#include <iostream>
using namespace std;

int main()
{
    int size = 10;
    int a[size] = {4, 3, 5, 7, 2, 22, 59, 37, 64, 99};

    cout << "Un-ordered data\n";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }

    for (int pass = 0; pass < size - 1; pass++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (a[i] > a[i + 1]) 
            { 
                int hold = a[i]; 
                a[i] = a[i + 1]; 
                a[i + 1] = hold; 
            }
        } 
    }

    cout << "\nData in ascending order\n";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}
