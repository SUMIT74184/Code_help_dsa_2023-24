#include <iostream>
#include <algorithm> // Include the algorithm header for swap
using namespace std;

int deleteduplicate(int arr[], int size) {
    int j = 0;
    int i = 1;
    for (int it = 0; it < size; it++) {
        if (arr[i] == arr[j]) {
            i++;
        } else {
            j++;
            swap(arr[i], arr[j]);
            i++;
        }
    }
    return j + 1;
}

int main() {
    int arr[] = {0, 0, 1, 1, 2, 2, 3, 3, 4};
    int size = sizeof(arr) / sizeof(int);
    int nas = deleteduplicate(arr, size);
    cout << "the value of nas: " << nas << endl; // Fix the typo here
    return 0;
}
