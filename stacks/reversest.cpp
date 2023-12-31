// #include<iostream>
// #include<stack>
// using namespace std;

// //inserting without an element
// void insertAtBottom(stack<int>&st){
//     while(st.empty()){
//        // st.push();
//         return;
//     }
//     int temp=st.top();//storing our top element
//     st.pop();
//     insertAtBottom(st);//using the recursion to solve the problem
//     //now in the last step we are abcktracking
//     st.push(temp);

// }

// void reverseAstack(stack<int>&st){
// while(st.empty()){
//     return;
// }

// int temp=st.top();
// st.pop();

// //recursion for thepoping and storing the top element
// reverseAstack(st);

// //inserting at the bottomour stored elemnt at the temp
// insertAtBottom(st);
// st.push(temp);

// }

// int main(){
// stack<int>st=cpystack;
// st.push(22);
// st.push(234);
// st.push(45);
// st.push(67);
// //int element=654;
// insertAtBottom(st);
//  cout<<"the size of the stack :"<<st.size()<<endl;
// //  cout<<st()<<endl;
// cout<<"the value before the stack was :"<<endl;

// // while(!cpystack.empty()){
// // cout<<cpystack.top()<<endl;
// // cpystack.pop();
// // }

//  reverseAstack(st);
// // // cout<<"value after the stack was reversed:"<<endl;
// while(!st.empty()){
// cout<<st.top()<<endl;
// st.pop();
// }
//     return 0;
// }

#include <iostream>
#include <stack>

using namespace std;

// Function to insert an element at the bottom of a stack
void insertAtBottom(stack<int> &stk, int item)
{
    // Base case: if the stack is empty, simply push the item
    if (stk.empty())
    {
        stk.push(item);
        return;
    }

    // Recursive case: pop the top element and insert the item at the bottom
    int topElement = stk.top();
    stk.pop();
    insertAtBottom(stk, item);

    // Push the top element back onto the stack
    stk.push(topElement);
}

// Function to reverse a stack using recursion
void reverseStack(stack<int> &stk)
{
    // Base case: if the stack is not empty, reverse it
    if (!stk.empty())
    {
        // Pop the top element
        int topElement = stk.top();
        stk.pop();

        // Reverse the remaining stack
        reverseStack(stk);

        // Insert the top element at the bottom
        insertAtBottom(stk, topElement);
    }
}

int main()
{
    stack<int> myStack;

    // Push elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    // Print the original stack
    stack<int> originalStack = myStack; // Make a copy of the stack
    cout << "Original Stack: ";
    while (!originalStack.empty())
    {
        cout << originalStack.top() << " ";
        originalStack.pop();
    }
    cout << endl;

    // Reverse the stack
    reverseStack(myStack);

    // Print the reversed stack
    cout << "Reversed Stack: ";
    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}
