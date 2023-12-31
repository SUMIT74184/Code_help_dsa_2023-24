#include<iostream>
using namespace std;

int sum(int n){
    if(n==1){
        return 1;
        
    }
    int ans=n+sum(n-1);
        return ans;
}




int printpow(int n){
    if(n==0){
        return 1;
    }

    int nas=2*printpow(n-1);
    cout<<nas;

    return nas;
}


void print(int n){
if(n==1){
    cout<<1<<" ";
    return;
}
cout<<n<<"";
print(n-1);
//tail recursion

}

int main(){
int n;
cout<<sum(5)<<endl;
//print(5);
//printpow(10);

    return 0;
}