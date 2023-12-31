#include<iostream>
using namespace std;


// int getUnique(int arr[],int size){
// int ans=0;
// for(int i=0;i<size;i++){
//     ans=ans^arr[i];
//xoring and getting the answer
// }
// return ans;
// }

int main(){

int arr[]={12,34,5};
int size=3;

int count=0;
//for(int k=0;k<size;k++){
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        cout<<arr[i]<< " "<<arr[j]<<" ";

    }
    cout<<endl;
}
cout<<arr[2]<<endl;
// count++;
// cout<<count<<endl;
// }
// int finans=getUnique(arr,size);
// cout<<finans<<endl;




    return 0;
}