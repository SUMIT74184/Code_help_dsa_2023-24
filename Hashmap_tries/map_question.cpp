#include<iostream>
#include<unordered_map>
using namespace std;


//input string count the frequmcy of each number
void countCharacter(unordered_map<char,int>& mapping,string str){
for(int i=0;i<str.length();i++){
    char c=str[i];
    mapping[c]++;
} 
}


int main(){
string str="lovebabbar";
unordered_map<char,int>mapping;
countCharacter(mapping,str);
 
 for(auto it:mapping){
    cout<<it.first<<"->"<<it.second<<endl;
 }

    return 0;
}