#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
class Node{
public:
int data;
Node*next;
Node*right;
Node*left;

Node(int val){
    this->data=val;
}
~Node(){
    cout<<"destructor for the particular leaf has been called"<<this->data<<endl;
}

};
int getKthsmallestElement(int arr[],int k,int n){
    priority_queue<int>q;
    for(int i=0;i<k;i++){
        int element=arr[i];
        q.push(element);
    }
    for(int i=k;i<n;i++){
    int element=arr[i];
    if(element<q.top()){//if the top element of the bst is larger then it will be replaces
        q.pop();
        q.push(element);
    }
}

int ans=q.top();
return ans;
}

int getKthgreaterElement(int arr[],int k,int n){
    priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<k;i++){
        int element=arr[i];
        q.push(element);
    }
    for(int i=k;i<n;i++){
    int element=arr[i];
    if(element>q.top()){//if the top element of the bst is larger then it will be replaces
        q.pop();
        q.push(element);
    }
}

int ans=q.top();
return ans;
}

int main(){
int arr[]={3,21,54,45,67,89,90};
int k=2;
int n=7;
cout<<"kth smallest element in the priority queue :"<<getKthsmallestElement(arr,k,n);
cout<<endl;

cout<<"kth largest element :"<<getKthgreaterElement(arr,k,n);
    return 0;
}