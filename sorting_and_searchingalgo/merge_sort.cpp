#include<iostream>
#include<math.h>
#include<vector>
//solving using recursion
using namespace std; 

void Merge(int arr[],int start,int end){
    int mid=(start+end)/2;
    //providing them the left
    int lenLeft=mid-start+1;//left side array
    int lenRight=end-mid;//right side of an array
 //creating the dynamic array
 int *left=new int[lenLeft];//first we will allocate the memory in the heap 
 int *right=new int[lenRight];

 //copy value from original array to left array
 int k=start;
 for(int i=0;i<lenLeft;i++){
    left[i]=arr[k];//copied value in the left array
    k++;
 }

  k=mid+1;
 for(int i=0;i<lenRight;i++){
    right[i]=arr[k];//copied value in the right array
    k++;
 }

//ACTUAL MERGE LOGIC
int leftIndex=0;
int rightIndex=0;

int mainArrayIndex=start;//copying in the main index.....mistake is always donr in this place

while(leftIndex<lenLeft &&rightIndex<lenRight){
    if(left[leftIndex]<right[rightIndex]){
     arr[mainArrayIndex]=left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }
    else{
        arr[mainArrayIndex]=right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }
}

//corner case if both the arrays are exhausted
//two case 
//if the left one is exhausted
while(rightIndex<lenRight){
    arr[mainArrayIndex]=right[rightIndex];
    mainArrayIndex++;
    rightIndex++;
}
//if the right one is exhausted
while(leftIndex<lenLeft){
       arr[mainArrayIndex]=left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
}

delete[]left;
delete[]right;
 //after that 
 //will deallocate using delete keyword
}
void MergeSort(int arr[],int start,int end){

if(start>=end){
    //invalid array
    return;
}
//if the array has only single element
if(start==end){
    return;
}
//breaking the array and then making the recursive call
int mid=(start+end)/2;
MergeSort(arr,start,mid);//1st recursive call for left part
MergeSort(arr,mid+1,end);//2nd recursive call for right part

Merge(arr,start,end);
}

int main(){
int arr[]={7, 2, 1, 8, 6, 3, 5, 4};
int size=8;
int start=0;
int end=size-1;

cout<<"before merger sort"<<endl;
for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
}
MergeSort(arr,start,end);
cout<<endl;
cout<<"After merger sort"<<endl;
for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
}
    return 0;
}