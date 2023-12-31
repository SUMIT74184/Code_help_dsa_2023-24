#include<iostream>
#include<vector>
using namespace std;

void printsubarrays_utils(vector<int>&nums,int start,int end){
    if(end==nums.size()-1){
        return;//our first base condition
    }
//first loop will start from the beginning
//it will be moving till the size which is the end
    for(int i=start;i<=end;i++){
        cout<<nums[i]<<" ";
    }cout<<endl;
    printsubarrays_utils(nums,start,end+1);//calling/usnig recursion 
    //by moving the end by one
}

//now to print the next set of subarrays together 
void printsubarray(vector<int>&nums){
    //we are using our start pointer
    for(int start=0;start<nums.size()-1;start++){
        int end=start;//making it equal to end
    printsubarrays_utils(nums,start,end);//calling our function 
    }
}


int main(){

vector<int>nums{2,3,4,5,6};
printsubarray(nums);
    return 0;
}