#include <iostream>
using namespace std;

// Insertion sort
void insertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++) 
    {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) 
        {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

// Selection sort
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

// Merge sort
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int left_arr[n1];
    int right_arr[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; ++i) 
    {
        left_arr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) 
    {
        right_arr[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (left_arr[i] <= right_arr[j]) 
        {
            arr[k] = left_arr[i];
            i++;
        } 
        else 
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left_arr
    while (i < n1) 
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right_arr
    while (j < n2) 
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right) 
    {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Quick sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

	// insertionSort(arr, n);
    // selectionSort(arr, n);
    // mergeSort(arr, 0, n - 1);
    quickSort(arr, 0, n - 1);
	
    // print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) 
    {
    cout << arr[i] << " ";
    }
    cout << endl;

	return 0;
}