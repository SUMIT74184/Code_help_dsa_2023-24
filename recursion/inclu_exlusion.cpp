#include<iostream>
using namespace std;

void subsequences(string str,string output,int index){
    if(index>=str.length()){
        cout<<output<<endl;
        return;
    }

    char ch=str[index];
    //exclude wala case hain
    subsequences(str,output,index+1);

    //include wala case
    output.push_back(ch);
     subsequences(str,output,index+1);
}



int main(){

string str="pqrs";
string output="";
int index=0;
subsequences(str,output,index);
    return 0;
}