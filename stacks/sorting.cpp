#include<iostream>
#include<stack>
using namespace std;

void sortedStack(stack<int>&st,int &element){
    //our first base condition to check the stack is empty or the element is smaller
if(st.empty()||st.top()<element){
st.push(element);
return;
}

//again same storing top element and popping it out
int temp=st.top();
st.pop();

sortedStack(st,element);

st.push(temp);
}

int main(){
stack<int>st;
st.push(10);
st.push(20);
st.push(30);
st.push(40);
int element=33;

sortedStack(st,element);
while(!st.empty()){
    cout<<st.top()<<endl;
    st.pop();
}

    return 0;
}