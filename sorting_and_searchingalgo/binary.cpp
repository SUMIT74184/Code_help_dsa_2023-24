#include <iostream>
using namespace std;

int binarysearch(int arr[], int target, int size) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
       
    int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            return mid;  // Return the index where the target element was found
        } 
        else if (arr[mid] > target) {
            end = mid - 1;
        } 
        else {
            start = mid + 1;
        }
    }

    return -1;  // Element not found
}

int main() {
    int arr[] = {2, 3, 4, 5, 16, 18, 19, 22};
    int target = 18;
    int size = 8;
    int result = binarysearch(arr, target, size);
    cout << "result is found " << result << endl;
    if (result != -1) {
        cout << "element found at index " << result << endl;
    } else {
        cout << "element not found" << endl;
    }

    return 0;
}
