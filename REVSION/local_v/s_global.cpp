#include<iostream>
using namespace std;
int x=900;//global variable

int main(){
int x=87;
cout<<x<<endl;//local variable
cout<<x<<endl;
cout<<::x<<endl;//accessing the global variable
    {
        int x=90;//scoped ..this is also known as scope local variable
        cout<<x<<endl;
        
    }
}