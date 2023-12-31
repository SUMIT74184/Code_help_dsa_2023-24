#include<iostream>
using namespace std;

int binarysearch(int arr[],int start,int end,int target){    
if(start>=end){
    return -1;
}
int mid=start+(end-start)/2;
if(arr[mid]==target){
    return mid;
}
    if(arr[mid]<target){
   // start=mid+1;
        return binarysearch(arr,mid+1,end,target);
    }
    else{
       // end=mid-1;
         return binarysearch(arr,start,mid-1,target);
    }
}

int main(){
int arr[]={10,20,30,40,50,66,74,83,92,100};
int size=10;
int start=0;
int end=size-1;
int target=89;

int isFound=binarysearch(arr,start,end,target);
if(isFound!=-1){
    cout<<"the target is present"<<isFound<<endl;

}
else{
    cout<<"target not found"<<isFound<<endl;
}


    return 0;
}