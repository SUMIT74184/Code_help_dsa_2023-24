#include<iostream>
#include<queue>
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

int maxDepth(Node*newNode){
    if(newNode==NULL){
        return 0;
    }
    int leftheight=maxDepth(newNode->left);
    int rightheight=maxDepth(newNode->right);

    int ans=max(leftheight,rightheight)+1;
    return ans;
}


int CalculateDiamert(Node*newNode){
    if(newNode==nullptr){
        return 0;
    }
    int option1=CalculateDiamert(newNode->left);//it may happen that the maximum edge is present in the left subtree
    //ot it may happen that it is present in the right subtree
    int option2=CalculateDiamert(newNode->right);
    int option3=maxDepth(newNode->left)+maxDepth(newNode->right);//we are calculating the maximum height from both side//we can call maxDepth as height
    int ans=max(option1,max(option2,option3));//finding the maximu answer
    return ans;
}

bool BalanceBianryTree(Node*newNode){
    if(newNode==NULL){
        return true;
    }
    int leftSubtree=maxDepth(newNode->left);
    int rightSubtree=maxDepth(newNode->right);
    int difference=abs(leftSubtree-rightSubtree);

    bool ansleft=BalanceBianryTree(newNode->left);
    bool ansRight=BalanceBianryTree(newNode->right);
    if(difference<=1){
        return true;
    }
    else{
        return false;
    }
}

bool PathSum_Helper(Node*newNode,int target){
    if(newNode==nullptr){
        return false;
    }
    int sum=0;
    sum+=newNode->data;
    if(newNode->left==NULL &&  newNode->right==NULL){
        if(sum==target){
            return true;
        }else{
            return false;
        }
    }
    return false;
}
bool pathSum(Node*newNode){
    int target=32;
   bool leftans=PathSum_Helper(newNode,target);
    bool rightans=PathSum_Helper(newNode,target);
    return leftans || rightans;

}

int main(){
    
// Node*root=nullptr;
// root=CreateTree();

Node*root=CreateTree();
// inordertraversal(root);

// cout<<"printing the value of inorder"<<endl;
// inordertraversal(root);
// cout<<endl;

// cout<<"printing the value of preorder"<<endl;
// PreOrderTraversal(root);
// cout<<endl;

// cout<<"printing the value of postorder"<<endl;
// PostorderTraversal(root);
// cout<<endl;

cout<<"printing the value of levelorder"<<endl;
LevelOrderTraversal(root);
cout<<endl;



int ans=maxDepth(root);
cout<<"the maximum height of the tree is"<<ans<<endl;




    return 0;
}