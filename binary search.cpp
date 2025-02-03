#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter sorted elements ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int target;
    cout << "Enter the element ";
    cin >> target;
    
    int result = binarySearch(arr, n, target);
    
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}
