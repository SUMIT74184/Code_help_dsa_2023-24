#include<iostream>
#include<stack>
using namespace std;
int main(){
stack<int>st;

st.push(10);
st.push(20);
st.push(30);

while(!st.empty()){
    st.pop();
    cout<<st.top()<<" ";
}


return 0;
}