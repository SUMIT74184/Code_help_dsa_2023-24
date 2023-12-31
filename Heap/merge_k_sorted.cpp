#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//class nodde
class mine{

};
class Node{
public:
int data;
int rowIndex;
int columnIndex;

Node(int a,int b,int c){
    this->data=a;
    this->rowIndex=b;
    this->columnIndex=c;
}


};
//comparator function to compare between the consecutinve array
class Comparator{
public:
bool operator()(Node*a,Node*b){
return a->data>b->data;// less than will used to min-heap
}
};
void mergeSortedArrays(int arr[][4],int n,int k,vector<int>&ans){

    priority_queue<Node*,vector<Node*>,Comparator>pq;
    //step:process the first k element
    for(int row=0;row<k;row++){
        int element=arr[row][0];//to process the first element of the arrays thats 0 is written
        Node*temp=new Node(element,row,0);//makin the dynamic array as temp
        pq.push(temp);
    }

    while(!pq.empty()){
        Node*temp=pq.top();
        pq.pop();
        int topData=temp->data;
        int topRow=temp->rowIndex;
        int topCol=temp->columnIndex;

        //storing the vector
        ans.push_back(topData);

        //next element for the same row,abhi kaara jisse bhi
        //use inset bhi kro

        if(topCol+1<n){
            //iska matlb row mein abhi bhi element baaki hai
            Node*newInfo=new Node(arr[topRow][topCol+1],topRow,topCol+1);
            pq.push(newInfo);
        }
    }
}



//implementing this program using the min-heap data structure

int main(){
int arr[3][4]={
                {2,4,6,8},
                {1,3,5,7},
                {5,9,11,13} 
                };
int k=3;
int n=4;
vector<int>ans;
mergeSortedArrays(arr,n,k,ans);
cout<<"printing the ans in the terminal"<<endl;
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}
    return 0;
}