//important problem
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//possible that the path may be closed
//out of bound condition
//check if not visited
bool isSafe(int srcx, int srcy, int newx, int newy, int maze[][4], int row, int col,  vector<vector<bool > > &visited) {
	if(
		(newx >=0 && newx <row) &&
		(newy >=0 && newy < col) &&
		maze[newx][newy] == 1 &&
		visited[newx][newy] == false
		) {
		return true;
		}
	else {
		return false;
	}
}



void printAllPath(int maze[][4],int row,int col,int srcx,int srcy,string &output,vector<vector<bool>>&visited)
{
//base case
if(srcx==row-1 && srcy==col-1){
    //reached the destination
    cout<<output<<endl;
    return;
    }

//up ka case first
int newx=srcx-1;
int newy=srcy;
    if(isSafe(srcx,srcy,newx,newy,maze,row,col,visited)){
    //mark visited
    visited[newx][newy]=true;
    //call recursion
    output.push_back('U');
	printAllPath(maze, row, col, newx, newy, output , visited );
    //backtracking
    output.pop_back();
    visited[newx][newy]=false;

}
//right case
 newx=srcx;
 newy=srcy+1;
    if(isSafe(srcx,srcy,newx,newy,maze,row,col,visited)){
    //mark visited
    visited[newx][newy]=true;
    //call recursion
    output.push_back('R');
  		printAllPath(maze, row, col, newx, newy, output , visited );
    //backtracking
    output.pop_back();
    visited[newx][newy]=false;

}
//down case
 newx=srcx+1;
 newy=srcy;
    if(isSafe(srcx,srcy,newx,newy,maze,row,col,visited)){
    //mark visited
    visited[newx][newy]=true;
    //call recursion
    output.push_back('D');
   		printAllPath(maze, row, col, newx, newy, output , visited );
    //backtracking
    output.pop_back();
    visited[newx][newy]=false;
}

//left case
 newx=srcx;
 newy=srcy-1;
    if(isSafe(srcx,srcy,newx,newy,maze,row,col,visited)){
    //mark visited
    visited[newx][newy]=true;
    //call recursion
    output.push_back('L');
		printAllPath(maze, row, col, newx, newy, output , visited );
    //backtracking
    output.pop_back();
    visited[newx][newy]=false;

}


}

int main(){
//important probelem
int maze[4][4]=
    {{1,0,0,0},
	{1,1,0,0},
	{1,1,1,0},
	{1,1,1,1}};
int row=4;
int col=4;

int srcx=0;
int srcy=0;

string output="";

//making 2d matrix named as visiited and marking all the position as false
vector<vector<bool>>visited(row,vector<bool>(col,false));
if(maze[0][0]==0){//src postion is close itself
    cout<<"No path exists"<<endl;
}
else{
    
    visited[srcx][srcy]=true;
    printAllPath(maze,row,col,srcx,srcy,output,visited);
}



    return 0;
}