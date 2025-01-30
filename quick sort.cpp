#include <iostream>
using namespace std;

int partition (int arr[],int low, int high)
{
    int pivot = arr[low];
    int i = (low);

    for ( int j=low+1; j<=high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low],arr[i]);
    return i;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr,low,high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void printarray (int arr[], int size)
{
    for (int i = 0;i<size;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;

    cout << "enter number of elements ";
    cin >> size;

    int* arr = new int[size];

    cout << "enter the elements ";
    for (int i = 0; i<size; i++)
    {
        cin >> arr[i];
    }

    cout << "unsorted array";
    printarray(arr,size);
    quicksort(arr,0,size-1);

    cout << "sorted array";
    printarray(arr,size);

    delete[]arr;

    return 0;
}