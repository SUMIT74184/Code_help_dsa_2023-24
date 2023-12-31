#include<iostream>
#include<string>
using namespace std;

void permutation(string str,int index){
if(index>=str.length()){
    cout<<str<<" ";
    return;
}

for(int j=index;j<str.length();j++){
    swap(str[index],str[j]);

    permutation(str,index+1);
   
      }
}

int main(){
string str="poqre";
int index=0;
permutation(str,index);

    return 0;
}