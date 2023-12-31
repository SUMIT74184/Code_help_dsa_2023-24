#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void Quicksort(vector<int>& v, int start, int end) {
    if (start >= end) {
        return;
    }

    int i = start - 1;
    int j = start;
    int pivot = end;

    while (j < pivot) {
        if (v[j] < v[pivot]) {
            i++;
            swap(v[i], v[j]);
        }
        j++;
    }
    //when j goes out of bound throughout
    i++;
    swap(v[i], v[pivot]);//we will reach to thst condition where pivot element will reach right place
    Quicksort(v, start, i - 1);//recursive call for partition 1
    Quicksort(v, i + 1, end);//recursive call for partition 2
}

void print(const vector<int>& v) {
    cout << "The sorted array is:";
    for (int i = 0; i < v.size(); i++) {
        cout << " " << v[i];
    }
    cout << endl;
}

int main() {
    vector<int> v = {7, 2, 1, 8, 6, 3, 5, 4};
    int start = 0;
    int size = 8;
    int end = size - 1;

    Quicksort(v, start, end);
    print(v);

    return 0;
}
