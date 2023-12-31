#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node*right;
    Node*left;

    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

Node*inserIntoBst(Node*root,int data){
if(root==NULL){
    root=new Node(data);
    return root;
}
if(data>root->data){
    root->right=inserIntoBst(root->right,data);
}else{
    root->left=inserIntoBst(root->left,data);
}
return root;
}

void CreateBst(Node*&root){
    //cout<<"enter the val :"<<endl;
    int data;
    cin>>data;

    while(data!=-1){
        root=inserIntoBst(root,data);
   //cout<<"enter data"<<endl;
        cin>>data;
    }
}


void LevelorderTraversal(Node *root) {
    //breadth wise traversal
  queue<Node *> qp;
  qp.push(root);
  qp.push(NULL);
  while (!qp.empty()) {
    Node *temp = qp.front();//fetching element from the front
    qp.pop();

    if (temp == NULL) {
      cout << endl;
      if (!qp.empty()) {
        qp.push(NULL);
      }
    } else {
      cout << temp->data << " ";
      if (temp->left != NULL) {
        qp.push(temp->left);
      }
      if (temp->right != NULL) {
        qp.push(temp->right);
      }
    }
  }

  // return root;
}
void storeInorderTraversal(Node*root,vector<int>&ans){
if(root==NULL){
    return;
}

storeInorderTraversal(root->left,ans);
ans.push_back(root->data);
storeInorderTraversal(root->right,ans);
}

void ReplaceUsingPostorder(Node*root,vector<int>in,int &index){
if(root==nullptr){
    return;
}
//LRN
ReplaceUsingPostorder(root->left,in,index);
ReplaceUsingPostorder(root->right,in,index);
root->data=in[index];
index++;
}

Node* ConvertBstintoMaxHeap(Node*root){
    vector<int>inorder;
    storeInorderTraversal(root,inorder);

    int index=0;
    ReplaceUsingPostorder(root->left,inorder,index);
    return root;

}

int main(){

Node*root=NULL;
CreateBst(root);
LevelorderTraversal(root);

cout<<endl;
root=ConvertBstintoMaxHeap(root);
cout<<"converting ti into the heap"<<endl;
LevelorderTraversal(root);

    return 0;
}