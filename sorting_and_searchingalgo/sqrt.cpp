#include<iostream>
using namespace std;

int findSqrt(int arr[], int &size, int &target) {
    int start = 0;
    int end = target;
    int ans = 0;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (mid*mid == target) {
            return mid;
        } else if (mid*mid< target) {
           
            start = mid + 1;
             ans=mid;
        } else if(mid*mid> target) {
            end = mid - 1;
        }
    }

    int mid = start + (end - start) / 2;
    return ans;
}

int main() {
    int arr[] = {2, 4, 9, 16, 25, 64};
    int size = 6;
    int target = 25;
    int ans = findSqrt(arr, size, target);
    cout << "The value is at index: " << ans << endl;

    return 0;
}
