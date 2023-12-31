#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};

Node *
createTree() { // creating the separate function fot hte creation of the tree

  int val;
  cin >> val;
  if (val == -1) {
    return NULL;
  }
  cout << "enter the value of root node" << endl;
  Node *root = new Node(val); // creating the general tree
  cout << "enter the value of the left node";
  root->left = createTree(); // left of the tree and calling the function again
                             // to create the tree on the left side of the tree
  cout << "enter the value of right node";
  root->right = createTree(); // right part of the tree
  return root;
}

void inordertraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  inordertraversal(root->left);
  cout << "root->val" << root->data << "";
  inordertraversal(root->right);
}

void preOrederTraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  cout << "root->val" << root->data << "";
  preOrederTraversal(root->left);
  preOrederTraversal(root->right);
}

void postordertraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  postordertraversal(root->left);
  postordertraversal(root->right);
  cout << root->data << "";
}

void LevelOrderTraversal(Node *root) {

  queue<Node *> qp;
  qp.push(root);
  qp.push(NULL);
  while (!qp.empty()) {
    Node *temp = qp.front();
    qp.pop();

    if (temp->left != NULL) {
      qp.push(temp->left);
    }
    if (temp->left != NULL) {
      qp.push(temp->right);
    }
  }
}

// vrious level are marked into the tree
// return the vector<int>which stores the left view roots
// we want only the left most element
// if level and root are equal then store the elements
void printleft_viewofbinary(Node *root, int level, vector<int> &leftindex) {
  if (root == NULL) { // leftindex is basically the left view
    return;
  }
  if (level == leftindex.size()) {
    leftindex.push_back(root->data);
  }
  printleft_viewofbinary(root->left, level + 1, leftindex);  // recursive call
  printleft_viewofbinary(root->right, level + 1, leftindex); // recursive call
  // if the tree consist of only the right node only
}
void right_viewofbinarytree(Node *root, int level, vector<int> &rightview) {
  // if(root==NULL){
  //   return;
  // }
  // if(level==rightview.size()){

  // }
}

int main() {
  Node *root = createTree();
  cout << root->data << endl;
  // input for the tree 10,20,40,-1,-1,50,70,110,-1,-1,,30,-1,-1
  LevelOrderTraversal(root);

  return 0;
}