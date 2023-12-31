#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> transpose(vector<vector<int>>&matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>>ans(m,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            swap(matrix[i][j],matrix[j][i]);
            cout<<matrix[i][j]<<" ";
        }cout<<endl;
    }
    return ans;
}


int main()
{
     vector<vector<int>> matrix = 
    {{1, 2, 3}, 
     {4, 5, 6}, 
     {7, 8, 9}};
     cout<<"before printing the value"<<endl;
     for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
              cout<<matrix[i][j]<<" ";
        } cout<<endl;
     }cout<<" "<<endl;
   
   
    transpose(matrix);

    return 0;
} 


