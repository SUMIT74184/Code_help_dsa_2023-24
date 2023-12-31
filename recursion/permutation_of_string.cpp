#include<iostream>
using namespace std;

void printpermutation(string str,int index){

    //base case
    if(index>=str.length()){
        cout<<str<<" ";
        return;
    }
    for(int j=index;j<str.length();j++){
        swap(str[index],str[j]);
         printpermutation(str,index+1);
         //backtracking if we are by refernce
        // swap(str[index],str[j]);
    }
      
}
int main(){

string str="abc";
int index=0;
printpermutation(str,index);
    return 0;
}