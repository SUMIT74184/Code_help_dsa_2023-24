#include<iostream>
using namespace std;


int main(){

int arr[20];
int n;
cin>>n;
for(int i=0;i<n;i++){
    cout<<"enter the elements"<<" "<<endl;
    cin>>arr[i];
}
  int sum=0;
for(int i=0;i<n;i++){
  
    sum=sum+arr[i];
  cout<< "the sum of an array are "<<sum<<endl;
 
   
}
  cout<< "the sum of an array are "<<sum<<endl;
    return 0;

}