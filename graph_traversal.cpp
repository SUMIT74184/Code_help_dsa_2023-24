#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

void bfs(vector<vector<int>>& graph, int start, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    // Assuming graph representation as an adjacency list (vector of vectors)
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3, 4},
        {0, 5},
        {1},
        {1},
        {2}
    };

    int vertices = graph.size();
    vector<bool> visited(vertices, false);

    cout << "BFS Traversal: ";
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            bfs(graph, i, visited);
        }
    }

    return 0;
}
