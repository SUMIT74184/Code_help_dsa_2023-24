// #include <iostream>
// #include <queue>
// #include <stdio.h>
// #include <vector>
// using namespace std;
// class Node {
// public:
//   int data;
//   Node *left;
//   Node *right;

//   Node(int val) {
//     this->data = val;
//     this->left = NULL;
//     this->right = NULL;
//   }
// };

// Node *
// createTree() { // creating the separate function fot hte creation of the tree

//   int val;
//   cin >> val;
//   if (val == -1) {
//     return NULL;
//   }
//   cout << "enter the value of root node" << endl;
//   Node *root = new Node(val); // creating the general tree
//   cout << "enter the value of the left node";
//   root->left = createTree(); // left of the tree and calling the function again
//                              // to create the tree on the left side of the tree
//   cout << "enter the value of right node";
//   root->right = createTree(); // right part of the tree
//   return root;
// }

// void inordertraversal(Node *root) {
//   if (root == NULL) {
//     return;
//   }
//   inordertraversal(root->left);
//   cout << "root->val" << root->data << "";
//   inordertraversal(root->right);
// }

// void preOrederTraversal(Node *root) {
//   if (root == NULL) {
//     return;
//   }
//   cout << "root->val" << root->data << "";
//   preOrederTraversal(root->left);
//   preOrederTraversal(root->right);
// }

// void postordertraversal(Node *root) {
//   if (root == NULL) {
//     return;
//   }
//   postordertraversal(root->left);
//   postordertraversal(root->right);
//   cout << root->data << "";
// }

// void LevelOrderTraversal(Node *root) {

//   queue<Node *> qp;
//   qp.push(root);
//   qp.push(NULL);
//   while (!qp.empty()) {
//     Node *temp = qp.front();
//     qp.pop();

//     if (temp->left != NULL) {
//       qp.push(temp->left);
//     }
//     if (temp->left != NULL) {
//       qp.push(temp->right);
//     }
//   }
// }

// // vrious level are marked into the tree
// // return the vector<int>which stores the left view roots
// // we want only the left most element
// // if level and root are equal then store the elements
// void printleft_viewofbinary(Node *root, int level, vector<int> &leftview) {
//   if (root == NULL) { // leftindex is basically the left view
//     return;
//   }
//   if (level == leftview.size()) {
//     leftview.push_back(root->data);
//   } 
//   printleft_viewofbinary(root->left, level + 1, leftview);  // recursive call
//   printleft_viewofbinary(root->right, level + 1, leftview); // recursive call
//   // if the tree consist of only the right node only
// }
// void right_viewofbinarytree(Node *root, int level, vector<int> &rightview) {
//   if(root==NULL){
//     return;
//   }
//   if(level==rightview.size()){
//     rightview.push_back(root->data);

//   }
//   right_viewofbinarytree(root->right,level+1,rightview);
//   right_viewofbinarytree(root->left,level+1,rightview);
 
// }

// int main() {
//   Node *root = createTree();
//   // cout << root->data << endl;
//   // input for the tree 10,20,40,-1,-1,50,70,110,-1,-1,,30,-1,-1
//   LevelOrderTraversal(root);

//   vector<int>leftView;
//   printleft_viewofbinary(root,0,leftView);
//   cout<<"printing the leftView of the tree"<<endl;
//   for(int i=0;i<leftView.size();i++){
//     cout<<leftView[i]<<" ";
//   }

//   return 0;
// }
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

Node *createTree() {
    int val;
    cin >> val;
    if (val == -1) {
        return NULL;
    }

    Node *root = new Node(val);
    cout << "Enter the value of left node: ";
    root->left = createTree();
    cout << "Enter the value of right node: ";
    root->right = createTree();
    return root;
}

void inorderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL) {
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
}

void printleft_viewofbinary(Node *root, int level, vector<int> &leftview) {
    if (root == NULL) {
        return;
    }

    if (level == leftview.size()) {
        leftview.push_back(root->data);
    }

    printleft_viewofbinary(root->left, level + 1, leftview);
    printleft_viewofbinary(root->right, level + 1, leftview);
}

int main() {
    Node *root = createTree();

    cout << "Inorder Traversal: ";
    inorderTraversal(root);

    cout << "\nPreorder Traversal: ";
    preOrderTraversal(root);

    cout << "\nPostorder Traversal: ";
    postOrderTraversal(root);

    cout << "\nLevel Order Traversal: ";
    levelOrderTraversal(root);

    cout << "\nLeft View of Binary Tree: ";
    vector<int> leftView;
    printleft_viewofbinary(root, 0, leftView);
    for (int i = 0; i < leftView.size(); i++) {
        cout << leftView[i] << " ";
    }

    return 0;
}
