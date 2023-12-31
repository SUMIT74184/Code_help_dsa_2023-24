#include <iostream>
#include<queue>
using namespace std;
class Node{
  public:
  int data;
  Node*left;
  Node*right;

//constructor created
  Node(int val){
    this->data=val;
    this->left=NULL;
    this->right=NULL;

  }

};

Node* createTree(){//creation of the function
  cout<<"enter the val"<<endl;
  int data;
  cin>>data;
  if(data==-1){//base case for the -1
    return NULL;

  }
//create node
  Node* newNode=new Node(data);

  // s2 create left subtree
 newNode->left=createTree();

  //s3 create right subtree
 newNode->right=createTree();
    return newNode;
}

void LevelOrderTraversal(Node*newNode){
queue<Node*>q;
Node* temp=q.front();
q.pop();
cout<<temp->data<<" ";
if(temp->left){
  q.push(temp->left);
}
if(temp->right){
  q.push(temp->right);
}
}

void InorderTraversal(Node*newNode){
//base case
if(newNode=NULL){
  return;
}
//LNR
InorderTraversal(newNode->left);
cout<<newNode->data<<" ";
InorderTraversal(newNode->right);
}

void PreOrderTraversal(Node*newNode){
  if(newNode=NULL){//base case for preorder traversal
  return;
}
//NLR
cout<<newNode->data<<" ";
PreOrderTraversal(newNode->left);
PreOrderTraversal(newNode->right);

}

void postOrderTraversal(Node*newNode){
  if(newNode==NULL){
    return;
  }
  postOrderTraversal(newNode->left);
  postOrderTraversal(newNode->right);
  cout<<newNode->data<<" ";
}

int height(Node*newNode){
  if(newNode==NULL){
    return 0;
  }
 int leftheight= height(newNode->left);
 int rightheight=height(newNode->right);
  int ans=max(leftheight,rightheight)+1;
  return ans;
}

int diameterofBinary(Node*newNode){
  int option1=diameterofBinary(newNode->left);
  int option2=diameterofBinary(newNode->right);
  int option3=height(newNode->left)+height(newNode->right);
  int ans=max(option1,max(option2,option3));
  return ans;
}

int main() {
  Node* root=createTree();
  cout<<root->data<<endl;

LevelOrderTraversal(root);

cout<<"height"<<height(root)<<endl;

cout<<"diameterofbinarytree :"<<diameterofBinary(root)<< " ";

  // cout << "Hello world!" << endl;
  return 0;
}