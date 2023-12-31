#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void solveFormedian(double& median, priority_queue<int>& max, priority_queue<int, vector<int>, greater<int>>& min, int element) {
    if (max.size() == min.size()) {//case 1
        if (element > median) {
            min.push(element);
            median = min.top();
        } else {
            max.push(element);
            median = max.top();
        }
    } else if (max.size() == min.size() + 1) {//case 2
        if (element > median) {
            min.push(element);
        } else {
            int maxTOP = max.top();
            max.pop();
            min.push(maxTOP);
            max.push(element);
        }
        median = (min.top() + max.top()) / 2.0;
    } else if (min.size() == max.size() + 1) {//case 3 
        if (element > median) {
            int minTOP = min.top();
            min.pop();
            max.push(minTOP);
            min.push(element);
           
        } else {
          max.push(element);
        }
        median = (min.top() + max.top()) / 2.0;
    }
}

int main() {
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;

    int arr[] = {12,11,10,8,4,2,3,15};
    int n = 8 ;
    double median = 0; // Initialize median with the first element
    for (int i = 0; i < n; i++) {
        int element = arr[i];
        solveFormedian(median, max, min, element);
        cout << "Median found: " << median << endl;
    }

    return 0;
}
