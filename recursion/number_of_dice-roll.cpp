#include<iostream>
using namespace std;


int rolling_dice(int n,int k,int target){
if(target<0) return 0;
if(n!=0 && target==0) return 0;
if(n==0 && target!=0) return 0;
if(n==0 && target==0) return 1;

int ans=0;
for(int i=0;i<=k;i++){//loop is working for the number ways to calculate the solutions
    ans+=rolling_dice(n-1,k,target-i);
//every time we assume the ways n will be reduced by 1
//and target will be reduced by by the value
}
return ans;
}

int main(){
int n=3;
int k=2;
int target=6;
 int myans=rolling_dice(3,53,60);
 cout<<"the possible ways to find :"<<myans;

    return 0;
}