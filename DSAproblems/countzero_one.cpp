#include<iostream>
#include<limits.h>
using namespace std;
    void CountZeroOnes(int arr[],int size){
        int onescount=0;
        int zerocount=0;
        for(int i=0;i<size;i++){
            if(arr[i]==0){
            zerocount++;
            }
            else
            onescount++;
        }


        cout <<"0  :"<<zerocount<<endl;
          cout <<"1  :"<<onescount<<endl;
    }

int main(){

cout<<INT_MIN<<endl;

cout<<INT_MAX<<endl;


int arr[]={0,0,0,1,0,1,1,1,1,0};
int size=10;
CountZeroOnes(arr,size);


    return 0;
}