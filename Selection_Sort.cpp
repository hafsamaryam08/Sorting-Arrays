#include <iostream>
using namespace std;

// Selection Sort Function
void selectionSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min_index]) 
            {
                min_index = j;
            }
        }
        if (min_index != i) 
        {
            swap(arr[i], arr[min_index]);
        }
    }
}

int main()
{
	int arr[] = {5, 2, 4, 1, 3};
	int n = sizeof(arr) / sizeof(arr[0]);

    // print unsorted array
    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr, n);
	
    // print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) 
    {
    cout << arr[i] << " ";
    }
    cout << endl;

	return 0;
}