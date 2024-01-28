#include<iostream>
#include<vector>
#include<queue>
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

    bool checkCycleUndirectedBFS(int src){
        queue<int>q;
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;

        //initial state
        q.push(src);//root node is always pushed inside the queue
        visited[src]=true;
        parent[src]=-1;

        while(!q.empty()){
            int frontNode=q.front();
            q.pop();

            for(auto nbr :adjLst[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                    parent[nbr]=frontNode;//setting the parent of that node
                }
               else if(visited[nbr]==true && frontNode !=parent[nbr]){//important consition to check the cycle
                    return true;
                }
            }
        }

        return false;
    }


    
    bool checkCycleDFS(int src, unordered_map<int, bool>& visited, int parent) {
        visited[src] = true;

        for (int nbr : adjLst[src]) {
            if (!visited[nbr]) {
                bool ans = checkCycleDFS(nbr, visited, src);
                if (ans) {
                    return true;
                }
            } else if (visited[nbr] && nbr != parent) {
                return true;
            }
        }

        return false;
    }

    bool containsCycle() {
        unordered_map<int, bool> visited;

        for (auto& vertex : adjLst) {
            int src = vertex.first;
            if (!visited[src]) {
                if (checkCycleDFS(src, visited, -1)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main(){
Graph g;
g.addEdge(0,1,1); 
g.addEdge(1,2,1);
g.addEdge(1,3,1);
g.addEdge(2,0,1);
int src=0;
bool cyclepresent=g.checkCycleUndirectedBFS(src);
if(!cyclepresent){
    cout<<"prensenr";

}else{
    cout<<"bhai dekhle";
}

    return 0;
}