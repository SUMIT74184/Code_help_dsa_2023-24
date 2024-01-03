#include<iostream>
#include<vector>
using namespace std;
//constant time complexity =time complexity depend upon the length of string
//used to find out the pattern hidden
//maultiway subtree
//most importatnt data structure

//two condition
//present----  traversal           absent---create,traversal
//for the same characters mark the last one with false

class TrieNode{
    public:
    char value;
    TrieNode*children[26];//array of pointer
    bool isTerminal;
    // TrieNode*left;
    // TrieNode*right;

    TrieNode(char val){
        this->value=val;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        this->isTerminal=false; 

    }


};
//insertion
void insertWord(TrieNode*root,string str){
    cout<<"recieved_word :"<<str<<" :insertion :"<<endl;
//using recursion right now 
if(str.length()==0){
    root->isTerminal=true;//lastnode is terminal mode marked as true 
    return;
}
    char ch=str[0];
    int index=ch-'a';//finding the index of the character 
    TrieNode*child;
    if(root->children[index]!=nullptr){
        child=root->children[index];
    }else{
        //create
        child=new TrieNode(ch);
        root->children[index]=child;
    }
    //recursion call
    insertWord(child,str.substr(1));
}
//if the terminal is marked then only we will get the marked string
int main(){
TrieNode* root=new TrieNode('-');
insertWord(root,"donation");
cout<<endl;
insertWord(root,"base");
    return 0;
}