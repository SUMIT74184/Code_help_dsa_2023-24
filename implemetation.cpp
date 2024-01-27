#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

class Graph{
public:
    unordered_map<int,list<int>>adjLst;
    void addEdge(int u, int v,bool direction){
        // direction->0->undirected
        // direction->1->directed
        if(direction==1){
            //u->v direction
            adjLst[u].push_back(v);
        }else{
            //direction==0
            //u--v both direction inward and outward
                adjLst[u].push_back(v);
                adjLst[v].push_back(u);
        }
        cout<<endl<<"printing the list "<<endl;
        printAdjLst();
        cout<<endl;
    }

    void printAdjLst(){
        for(auto i:adjLst){
            cout<<i.first<<"->";
            for(auto neighbour :i.second){
                cout<<neighbour<<",";
            }
            cout<<"}"<<endl;
        }
    }
};

int main(){
Graph g;
g.addEdge(0,1,1); 
g.addEdge(1,2,1);
g.addEdge(1,3,1);
g.addEdge(2,3,1);

    return 0;
}