#include <iostream>
using namespace std;

int findfirstoccurence(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            ans = mid;
            end= mid - 1;
        } // similary for the last occurence can aslo be implemented

        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
    }
    int mid = start + (end - start) / 2;

    return ans;
}
int main()
{ // similar elements are found in which the first one to be return
    int arr[] = {10, 20, 30, 30, 30, 30, 40, 50, 60, 70};
    int size = 10;
    int target = 30;
    int answer = findfirstoccurence(arr, size, target);

    if (answer != 0)
    {
        cout << "the elemient is found at the index " << answer;
    }
    else
    {
        cout << "not found" << endl;
    }
    return 0;
}