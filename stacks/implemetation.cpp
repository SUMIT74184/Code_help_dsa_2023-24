#include<iostream>
#include<stack>
using namespace std;

int main(){
stack<int>st;

st.push(323);
st.push(312);
st.push(321);
// cout<<st.push<<endl;
if(!st.empty()){
    cout<<"the stack is already filled"<<endl;
}
else{
    cout<<"stack is empty"<<endl;
}
st.pop();
cout<<"the size of the stack is  :"<<st.size()<<endl;

cout<<"the top element of thse stack is :"<<st.top()<<endl;
return 0;
}