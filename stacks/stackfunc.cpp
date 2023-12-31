#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int>&st,int &element){
    while(st.empty()){
        st.push(element);
        return;
    }
    int temp=st.top();//storing our top element
    st.pop();
    insertAtBottom(st,element);//using the recursion to solve the problem
    //now in the last step we are abcktracking
    st.push(temp);

}

int main(){
stack<int>st;
st.push(22);
st.push(234);
st.push(45);
st.push(67);
int element=654;
insertAtBottom(st,element);
 cout<<"the size of the stack :"<<st.size()<<endl;
//  cout<<st()<<endl;


while(!st.empty()){
cout<<st.top()<<endl;
st.pop();

}cout<<endl;
    return 0;
}

