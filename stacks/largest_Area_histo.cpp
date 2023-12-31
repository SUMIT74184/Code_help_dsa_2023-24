#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

 vector<int> NextSmallerElem(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);
        for (int i = arr.size() - 1; i >= 0; i--) {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> PrevSmallerElem(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < arr.size(); i++) {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = NextSmallerElem(heights);

        // Fix 1: Loop condition should be 'i < next.size()' instead of 'i <= next.size()'
        for (int i = 0; i < next.size(); i++) {
            if (next[i] == -1) {
                next[i] = heights.size();
            }
        }

        vector<int> prev = PrevSmallerElem(heights);
        int MaxiArea = INT_MIN;

        // Fix 2: Loop condition should be 'i < heights.size()' instead of 'i <= heights.size()'
        for (int i = 0; i < heights.size(); i++) {
            int length = heights[i];
            int width = next[i] - prev[i] - 1;

            int CurrArea = length * width;
            MaxiArea = max(MaxiArea, CurrArea);
        }
        return MaxiArea;
    }
int main() {
    // Example usage
    vector<int> Height = {6, 2, 5, 4, 5, 1, 6};
    int result = largestRectangleArea(Height);

    cout << "Largest Rectangle Area: " << result << endl;

    return 0;
}
