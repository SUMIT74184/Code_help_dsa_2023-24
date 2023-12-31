#include<iostream>
using namespace std;

inline int func(int n){
    n=34;
    cout<<"the value is:"<<endl;
    return n;
}
int a=90;

int a1=10;//global variables
// cout<<"the value of the a"<<a<<endl;
int main(){
cout<<func(341)<<endl;
// int a=101;
//int b=89;
cout<<"the value of a :"<<a<<endl;
    return 0;
}
