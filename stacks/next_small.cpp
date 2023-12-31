#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> NextSmallerElem(int *arr,int size,vector<int>&ans){
    stack<int>st;
    st.push(-1);
    for(int i=size-1;i>=0;i--){//going from right to left
        int curr=arr[i];//storing the element in the current
        while(st.top()>=curr){//if the top element in the top is greater than cuurent
            st.pop();//pop out all the element

        }
         ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}


int main(){

 int arr[] = {8, 4, 6, 2, 3};
    int size = 5;
    vector<int> result(size);

    result = NextSmallerElem(arr, size, result);

    // Printing the result
    for(int i = 0; i < size; i++){
        cout << result[i] << " ";
    }

    return 0;
}