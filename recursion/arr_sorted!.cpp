#include<iostream>
using namespace std;

bool checksorted(int arr[],int size, int index){
    if(index>=size){
        return true;
        //base case
    }
    if(arr[index]>arr[index-1]){
        bool ans=checksorted(arr,size,index+1);
        return ans;
        //processing case
    }
    else{
        return false;
    }

}


int main(){
int arr[]={10,20,30,2};
int size=4;
int index=1;

bool isSorted=checksorted(arr,size,index);

if(isSorted){
    cout<<"the array is already sorted"<<endl;
}
else{
    cout<<"the array is not sorted"<<endl;
}

    return 0;
}