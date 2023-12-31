#include<iostream>
#include<limits.h>

using namespace std;



int findminnumof(int arr[],int size){
     int min_ans=INT_MAX;
    for(int i=0;i<size;i++){
        if(arr[i]<min_ans){
            min_ans=arr[i];
        }
    }
   // return min_ans;
}

int main(){
    int arr[]={23,4,5,66,78,90};
    int size=6;

int minimum=findminnumof(arr,size);
cout<<"minimum number is"<<minimum<<endl;

    return 0;
}