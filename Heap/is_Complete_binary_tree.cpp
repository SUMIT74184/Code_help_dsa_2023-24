#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;
class info{
    public:
    int maxVal;
    bool isHeap;
    info*left;
    info*right;
    int data;

    info(int a,bool b){
    this->maxVal=a;
    this->isHeap=b;
    }
};

info checkIsCompletebinarttree(info*root){
    if(root==NULL){//base case
        info*temp;
        temp.maxVal=INT_MIN;
        temp.isHeap=true;
        return temp;
    }
    if(root->left==NULL && root->right==NULL){
        info*temp;
        temp.maxVal=root->data;
        temp.isHeap=true;
        return temp;

    }
    info leftAns=checkIsCompletebinarttree(root->left);
    info rightAns=checkIsCompletebinarttree(root->right);
    //1 case 
    if(root->data && leftAns.maxVal && root->data>rightAns.maxVal &&
    leftAns.isHeap && rightAns.isHeap){
        info ans;
        ans.maxVal=root->data;
        ans.isHeap=true;
        return ans;
    }
    else{
        ans.maxVal=max(root->data, max(leftAns.maxVal,rightAns,maxVal));
        return ans;
    }
}

int main(){


    return 0;
}