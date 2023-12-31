#include<iostream>
#include<vector>
using namespace std;




void bublesort( vector<int>&v){
int n=v.size();
for(int i=0;i<n-1;i++){//first iterators for n-1 .....position
    for(int j=0;j<n-i-1;j++){//defines the comparison
        if(v[j]>v[j+1]){//both increaing and decreasing order can be implemented using the bubble sort
            swap(v[j],v[j+1]);
        }
    }
}



}
void print(vector<int>&v){
    for(int i=0;i<v.size();i++){
        cout<<"printing...."<<v[i]<<endl;
    }
}



int main(){
    vector<int>v={5,14,-53,332,891};
    print(v);
    cout<<" after bubble sort"<<endl;
    bublesort(v);
    print(v);


    return 0;
}