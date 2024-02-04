#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*left;
Node*right;

Node(int val){
    this->data=val;
    this->left=NULL;
    this->right=NULL;
}
}; 

pair<int,int> height(Node*root){
    if(!root){
        return {0,0};
    }
    auto lh=height(root->left);
    auto rh=height(root->right);

    int sum=root->data;
    if(lh.first==rh.first){
        sum+=lh.second>rh.second ?lh.second :rh.second;
    }
    else if(lh.first >rh.first){
        sum+=lh.second;
       
    }
    else{
        sum+=rh.second;
    }
     return {max(lh.first,rh.first)+1,sum};
}
int SumlongestHeight(Node*root){
auto h=height(root);
return h.second;
    


}

int main(){

    return 0;
}