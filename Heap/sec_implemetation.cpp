#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Node{
public:
int data;
Node*right;
Node*left;

Node(int val){
    this->data=val;
    this->right=NULL;
    this->left=NULL;
}
};


int main(){
//by default the max heap is created using the priority queue
//both of the operation for max heap,min heap are executed in O(1) time complexity
priority_queue<int>q;//by default
priority_queue<int,vector<int>,greater<int>>qm;//syntax for min heap
qm.push(100);
qm.push(90);
qm.push(78);
cout<<"top elemwnt of the min heap"<<qm.top()<<endl;
qm.pop();
cout<<"the top element after the removal from minheap.."<< qm.top()<<endl;
// q.push(10);
// q.push(40);
// q.push(45);
// cout<<"top element of the heap,,"<<q.top()<<endl;
    return 0;
}