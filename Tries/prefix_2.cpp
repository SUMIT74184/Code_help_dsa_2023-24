#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
int data;
Node*children[26];
 bool isTerminal;//mistake

Node(int val){
    this->data=val;
    for(int i=0;i<26;i++){
        children[i]=NULL;
    }
this->isTerminal=false;
}
};
void insertWord(Node* root, string word) {
  //cout << "recieved word: " << word << " for insertion " << endl;
  //base case
  if(word.length() == 0) {
    root->isTerminal = true;
    return;
  }

  char ch = word[0];
  int index = ch - 'a';
  Node* child;
  if(root->children[index] != NULL) {
    //present
      child = root->children[index];
  }
  else {
    //absent
     child = new Node(ch);
     root->children[index] = child;
  }

  //recursion
  insertWord(child, word.substr(1));

}

void storeString(Node* root, vector<string>& ans, string &input, string& prefix) {
  // base case
  if (root->isTerminal == true) {
    // ans store
    ans.push_back(prefix + input);
    // return ?
  }

  for (char ch = 'a'; ch <= 'z'; ch++) {
    int index = ch - 'a';
    Node* next = root->children[index];
    if (next != NULL) {
      // child exist
      input.push_back(ch);
      // baaaki recursion
      storeString(next, ans, input, prefix);
      // backtrack
      input.pop_back();
    }
  }
}


vector<vector<string>>getSolveSuggestion(Node*root,string input){
    //base case
    vector<vector<string>>output;
    Node*prev=root;
    string inputhelper="";

    for(int i=0;i<input.length();i++){
        char lastchar=input[i];
        int index=lastchar-'a';
        Node*curr=prev->children[index];

        if(curr==NULL){
            break;
        }
        else{
            vector<string>downstring;
            inputhelper.push_back(lastchar);
            string dummy="";
            storeString(curr,downstring,inputhelper,dummy);
            output.push_back(downstring);

            //important step
            prev=curr;
        }
    }
    return output;
}

int main(){
Node*root=new Node('-');
insertWord(root,"lonely");
insertWord(root,"lovely");
insertWord(root,"love");
insertWord(root,"louis");
insertWord(root,"lost");


vector<vector<string>>ans=getSolveSuggestion(root,"lo");
for(int i=0;i<ans.size();i++){
    cout<<i<<" ->";
    for(auto str :ans[i]){
        cout<<str<<" ,";

    }cout<<endl;
}

    return 0;
}