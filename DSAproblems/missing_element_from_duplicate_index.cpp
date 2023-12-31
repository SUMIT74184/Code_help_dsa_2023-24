#include<iostream>
using namespace std;

// void duplicateindex(int*arr,int size){

// for(int i=0;i<size;i++){
// int index=abs(arr[i]);
//  if(arr[index-1]>0){
//     arr[index-1] *=-1;
//  }
// }

// for(int i=0;i<size;i++){
// if(arr[i]>0){
//     cout<<i+1<<endl;

// }

// }


// }

void swaping(int *arr,int size){
    int i=0;
    while (i<size)
    {
        int index=arr[i]-1;//array starts from 0 here but index start from 1
    if(arr[index]!=arr[i]){
    swap(arr[index],arr[i]);
    
    }
    else{
        i++;
    }
    }
 for(int i=0;i<size;i++){
    if(arr[i]!=i+1){
    cout<<"printing"<<" "<<i+1<<endl;
    }
 }
    


}

int main() {
int arr[]={1,4,5,6,2};
int size=sizeof(arr)/sizeof(int);
//duplicateindex(arr,size);
 swaping(arr,size);



    return 0;
}