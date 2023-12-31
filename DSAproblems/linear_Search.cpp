#include<iostream>
using namespace std;



bool LinearSearch(int arr[],int size,int target){
for(int i=0;i<size;i++){
    if(arr[i]==target){
        return true;
    }
}

    return false;


}

int main(){
int arr[5]={2,3,4,5,6};
int target=4;
bool flag=0;
int size=5;
bool ans= LinearSearch(arr,size,target);
if(ans==1){
    cout<<"key has been succesfully found in the array"<<endl;

}
else{
    cout<<"not found plz try again"<<endl;
}

    return 0;
}