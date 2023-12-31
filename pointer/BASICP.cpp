#include<iostream>
using namespace std;

void solve(int* &p){
    * p=*p+1;
}


int main(){

    int a=9;
    int *ptr=&a;
    cout<<"the valueof ptr "<<ptr<<endl;
    cout<<"the add of ptr "<<&ptr<<endl;
    cout<<"the value of ptr "<<*ptr<<endl;
    solve(ptr);
     cout<<"the valueof ptr "<<ptr<<endl;
    cout<<"the add of ptr "<<&ptr<<endl;
    cout<<"the value of ptr "<<*ptr<<endl;

    return 0;
}