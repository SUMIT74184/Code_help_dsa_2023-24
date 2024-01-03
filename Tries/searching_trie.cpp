#include<iostream>
using namespace std;
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
void insertWord(TrieNode*root,string str){
  //  cout<<"recieved_word :"<<str<<" :insertion :"<<endl;
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
bool searchingInTrie(TrieNode*root,string str){
    if(str.length()==0){//base case
        return root->isTerminal;
    }
    char ch=str[0];//no need to compare
    int index=ch-'a';
    TrieNode*child;
    if(root->children[index]!=nullptr){
        child=root->children[index];//traverse through it 
       // return true;
    }else{
        return false;
    }
    bool searchingAns=searchingInTrie(child,str.substr(1));
    return searchingAns;

}
//deletion code in constant time complexity
void DeletionInTrie(TrieNode*root,string str){
    if(str.length()==0){
         root->isTerminal=false;
         return;
    }
    char ch=str[0];//for the first word
    int index=ch-'a';//index of that word
    TrieNode*child;//initializing the child node

    if(root->children[index]!=nullptr){
        child=root->children[index];
    }else{
        return;
    }
    DeletionInTrie(root,str.substr(1));
}
int main(){
TrieNode*root=new TrieNode('-');
insertWord(root,"cater");
insertWord(root,"loved");
insertWord(root,"com");
insertWord(root,"loved");


if(searchingInTrie(root,"cating")){
    cout<<"found"<<endl;
}else{
    cout<<"not found yaar"<<endl;
}

    return 0;
}