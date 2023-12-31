#include <iostream>
using namespace std;

 void duplicateindex(int arr[],int size){
for(int i=0;i<size;i++){
  int index=abs(arr[i]);
  if(arr[index-1]>0){
    arr[index-1]*=-1;
    
  }
  
}
for(int i=0;i<size;i++){
  if(arr[i]>0){
     // cout<<arr[i]<<" "<<endl;
  cout<<arr[i];
  cout<<i+1<<" ";
  }
}
  
}

// int i=0;
// while(i<size){
//   int index=arr[i]-1;
//   if(arr[i]!=arr[index]){
//     swap(arr[i],arr[index]);
//   }
// else{
//     i++;
// }


//   for(int i=0;i<size;++i){
//     if(arr[i]!=i+1){
//     cout<<i+1<<endl;
//     }
//   }
// }
//  }


int main() {
 int arr[]={1,3,4,3,5,6,8,6};
  int size=sizeof(arr)/sizeof(int);
duplicateindex(arr, size);
cout<<"sumit";
  return 0;
}