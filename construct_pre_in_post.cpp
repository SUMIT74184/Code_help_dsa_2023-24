#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;


    Node(int val){
        this->data=val;
        this->left=nullptr;
        this->right=nullptr;
    }

};

Node*CreateTree(){
    cout<<"enter the value"<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    Node*newNode=new Node(data);
    newNode->left=CreateTree();//Actual use of recursion
    newNode->right=CreateTree();
    
    return newNode;
}

void inordertraversal(Node*newNode){
    if(newNode==nullptr){
        return;
    }
  inordertraversal(newNode->left);
  cout<<newNode->data<<" ";
  inordertraversal(newNode->right);

}

void PostorderTraversal(Node*newNode){
     if(newNode==nullptr){
        return;
    }
    PostorderTraversal(newNode->left);
    cout<<newNode->data<<" ";
    PostorderTraversal(newNode->right);
}

void PreOrderTraversal(Node*newNode){
     if(newNode==nullptr){
        return;
    }
      cout<<newNode->data<<" ";
    PreOrderTraversal(newNode->left);
    PreOrderTraversal(newNode->right);
}

void LevelOrderTraversal(Node*newNode){
    //base case
    if(newNode==nullptr){
        return;
    }

    queue<Node*>q;
    q.push(newNode);

    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        if(q.front()==NULL){//handling the null value in the front
            cout<<endl;
        q.push(NULL);
        
        }
        else{
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
        q.push(temp->left);
        }
        if(temp->right!=NULL){
        q.push(temp->right);
        }
        }
     

    }

}

void CreateMapping(int inorder[],int size,map<int,int>&valueToIndex){
    for(int i=0;i<size;i++){
        int element=inorder[i];//mistake part
        int index=i;
        valueToIndex[element]=index;

    }
}

int searchInorder(int inorder[],int size,int target){
    for(int i=0;i<size;i++){
        if(inorder[i]==target){
            return i;
        }
    }
    return -1;
}

Node*ConstructTree(map<int,int>&valueToIndex,int preorder[],int inorder[],int &preIndex,int inorderStart,int inorderEnd,int size){

if(preIndex>=size || inorderStart>inorderEnd){
    return NULL;
}

    int element=preorder[preIndex];
    preIndex++;
    Node*root=new Node(element);
    //element is searched

    // int position=searchInorder(inorder,size,element);

    //optimising the searching the time complexity
    int position=valueToIndex[element];

    root->left=ConstructTree(valueToIndex,preorder,inorder,preIndex,inorderStart,position-1,size);
    root->right=ConstructTree(valueToIndex,preorder,inorder,preIndex,position+1,inorderEnd,size);
    return root;

}

int main(){
    // int inorder[]={10,8,6,2,4,12};
    // int preorder[]={2,8,10,6,4,12};
    // int size=6;
    // int preIndex=0;
    // int inorderStart=0;
    // int inorderEnd=5;
    // map<int,int>valueToindexMap;
    // CreateMapping(inorder,size,valueToindexMap);

    // Node*root=ConstructTree(valueToindexMap,preorder,inorder,preIndex,inorderStart,inorderEnd,size);


    int inorder[]={8,14,6,2,10,4};
    int postorder[]={8,6,14,4,10,2};
    int size=6;
    int postIndex=size-1;
    int inorderStart=0;
    int inorderEnd=size-1;
    map<int,int>valueToindexMap;
    CreateMapping(inorder,size,valueToindexMap);
    // Node*root=ConstructTreePost();
    cout<<"printing teh value"<<endl;
    // LevelOrderTraversal(root);
    cout<<endl;


  return 0;
}