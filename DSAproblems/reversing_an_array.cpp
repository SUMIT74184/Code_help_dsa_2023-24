#include<iostream>
using namespace std;

void reverse_anarr(int arr[],int size){
    int left=0;
int right=size-1;
while(left<=right){
    swap(arr[left],arr[right]);
    left++;
    right--;

}

cout<<reverse_anarr<<endl;
}



void printextreame(int arr[],int size)
{
int left=0;
int right=size-1;
while(left<=right){
    cout<<arr[left];
    cout<<arr[right];
    left++;
    right--;

}
for(int i=0;i<size;i++){
   // cout<<"reversal of an"<<arr[i]<<endl;
}
}







int main(){
int arr[6]={10,20,30,40,50,60};
int size=6;

printextreame(arr,size);
reverse_anarr(arr,size);

    return 0;
}