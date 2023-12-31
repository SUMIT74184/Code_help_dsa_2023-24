#include<iostream>
using namespace std;


int findingMissingel(int *arr,int n){
int start=0;
int end=n-1;

int ans=-1;

while(start<=end){
    int mid=start+(end-start)/2;
    int diff=arr[mid]-mid;
    if(diff==1){
        start=mid+1;
    }
    else{
        ans=mid;
        end=mid-1;
    }
}
return ans+1;
}

int main(){
int arr[10]={1,2,3,4,5,6,7,8,9,11};
int n=10;
int findalasn=findingMissingel(arr,n);
cout<<"the missing element of an array :"<<findalasn<<endl;

 

    return 0;
}