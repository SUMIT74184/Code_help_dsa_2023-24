#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> PreviosSmallerElem(int *arr,int size,vector<int>&ans){
    stack<int>st;
    st.push(-1);
    for(int i=0;i<=size-1;i++){//moivng the stack from the left to right
        int curr=arr[i];//storing our current element
        while(st.top()>=curr){//
            st.pop();

        }
         ans[i] = st.top();//if the top element is smaller tahn the current element
         //then do not execute the while loop and store it to ans
        st.push(curr);//also push the element
    }

    return ans;
}


int main(){

 int arr[] = {8, 4, 6, 2, 3};
    int size = 5;
    vector<int> result(size);

    result = PreviosSmallerElem(arr, size, result);

    // Printing the result
    for(int i = 0; i < size; i++){
        cout << result[i] << " ";
    }

    return 0;
}