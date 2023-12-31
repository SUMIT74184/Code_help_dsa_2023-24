#include<iostream>
#include<stack>

using namespace std;

void insertingInsort(stack<int>&st,int &element){
    if(st.empty()||st.top()<element){
        st.push(element);
        return;
    }
    int temp=st.top();
    st.pop();

    insertingInsort(st,element);

    st.push(temp);

}

//in this function we are popping out all these element from the stack 
void sorting_comp(stack<int>&st){
    if(st.empty()){
        return;
    }
    int temp=st.top();
    st.pop();

    sorting_comp(st);
    //using recursion to remove the element and 
    //also storing them at the same time

    insertingInsort(st,temp);
    //recalling our previous method by comparing the elements and then sorting and inserting 
}



int main(){
stack<int>st;


    st.push(110);
    st.push(21);
    st.push(303);
    st.push(410);
    int element=32;

    insertingInsort(st,element);
    sorting_comp(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}