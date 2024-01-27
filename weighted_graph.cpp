#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
// template <typename T>
class Graph{
public:
    unordered_map<int,list<pair<int,int>>>adjLst;
    void addEdge(int u,int v,int wt,bool direction){
        //direction-0->undirected
        //direction-1->directed
        if(direction==1){
            adjLst[u].push_back({v,wt});
        }else{
            //u----v
            //u->v
            //v->u
            adjLst[u].push_back({v,wt});//we can also use make pair function
            adjLst[v].push_back({u,wt});
            printAdjLst();
        }
    }

    void printAdjLst(){
        for(auto i: adjLst){
            cout<<i.first<<": {";
            for(pair<int,int>p:i.second){
                cout<<"{"<<p.first<<" ,"<<p.second<<"},";
            }
            cout<<"}"<<endl;
        }  
    }
};


int main(){
Graph g;
g.addEdge(0,1,5,0);
g.addEdge(1,2,10,0);
g.addEdge(1,3,20,0);
g.addEdge(2,3,50,0);

    return 0;
}