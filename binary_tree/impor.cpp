#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
#include <vector>

// #include "binary_search_tree.cpp"


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

Node *createTree() { // creating the separate function fot hte creation of the tree

  int val;
  cin >> val;
  if (val == -1) {
    return NULL;
  }
  // cout << "enter the value of root node :" << endl;
  Node *root = new Node(val); // creating the general tree
  cout << "enter the value of the left node :";
  root->left = createTree(); // left of the tree and calling the function again
  // to create the tree on the left side of the tree
  cout << "enter the value of right node :";
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
  cout << endl;
  while (!qp.empty()) {
    Node *temp = qp.front();
    qp.pop();

    if (temp->left != NULL) {
      qp.push(temp->left);
    }
    if (temp->right != NULL) {
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
void printright_viewofbinarytree(Node *root, int level,
                                 vector<int> &rightview) {
  if (root == NULL) {
    return;
  }
  if (level == rightview.size()) { // our main recursive condtion that if level
                                   // and indexsize is same then only
    rightview.push_back(root->data); // we will store the element
  }
  printright_viewofbinarytree(root->right, level + 1, rightview);
  printright_viewofbinarytree(root->left, level + 1, rightview);
}

void printtopview(Node *root) {
  map<int, int> hdtonNode;
  queue<pair<Node *, int>> q;
  q.push(make_pair(root, 0));

  while (!q.empty()) {
    // storing the pair in the form of NODE n int value defines the level
    pair<Node *, int> temp = q.front();
    q.pop();

    Node *frontNode = temp.first; // first values is storing the node value
    int hd = temp.second;         // second value is storing the level value

    // if the map does not contain entry for the level then only insert values
    // to it
    // basically we are finding for hd distance
    if (hdtonNode.find(hd) == hdtonNode.end()) { // empty condition checking
      hdtonNode[hd] = frontNode->data;
    }

    // giving the call for the child node
    if (frontNode->left != NULL) {
      q.push(make_pair(frontNode->left, hd - 1));
    } // left child

    // giving the call for the right child
    if (frontNode->right != NULL) {
      q.push(make_pair(frontNode->right, hd + 1));
    }

    for (auto it : hdtonNode) {
      cout << it.second << "";
    }
  }
}

void printLeftBoundary(Node *root) {
  if (root == NULL) {
    return;
  }
  if (root->left == NULL && root->right == NULL) {
    return;
  }
  cout << root->data << " ";
  if (root->left != NULL) {
    printLeftBoundary(root->left);
  } else {
    printLeftBoundary(root->right);
  }
}

void printLeafBoundary(Node *root) {
  if (root == NULL) {
    return;
  }
  if (root->left == NULL && root->right == NULL) {   // if they are null then it is last nodes
    cout << root->data << " "; // now we will print that node particularly
  }
  printLeafBoundary(root->left); // recursive call for left and right side of the tree
  printLeafBoundary(root->right);
}

void printRightBoundary(Node *root) {
  if (root == NULL) {
    return;
  }
  if (root->left == NULL && root->right == NULL) {
    return;
  }

  if (root->right != NULL) {
    printRightBoundary(root->right);
  } else {
    printRightBoundary(root->left);
  }
  cout << root->data << " ";
}

void printboundarytraversal(Node*root){
  if(root==NULL){
    return;
  }
  
  printLeftBoundary(root);
  printLeafBoundary(root);
  if(root->right!=NULL){
    printRightBoundary(root->right);
  }else{
    printRightBoundary(root->left);
  }




}
int main() {
  Node *root = NULL;
 createTree();
 LevelOrderTraversal(root);
//   // cout << root->data << endl;
//   //  input for the tree 10,20,40,-1,-1,50,70,110,-1,-1,,30,-1,-1


  
//   // vector<int> leftindex;
//   // LevelOrderTraversal(root);
//   // cout << "printing the leftview answer" << endl;
//   // printleft_viewofbinary(root, 0, leftindex);
//   // for (auto val : leftindex) {
//   //   cout << "printing the values" << val;
//   // }
//   // vector<int> rightview;
//   // cout << "printing rightview answer" << endl;
//   // printright_viewofbinarytree(root, 0, rightview);
//   // for (int i = 0; i < rightview.size(); i++) {
//   //   cout << "printing the right view of binary tree" << rightview[i];
//   // }

  return 0;
}