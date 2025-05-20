#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;

/*
    32. Write a program to create graph and traverse it using BFS. 

    33. Write a program to create graph and traverse it using DFS.
    
*/

class Graph {
    int V;  // Number of vertices
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        // For undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void bfs(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        cout << "BFS traversal: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void dfs(int start) {
        vector<bool> visited(V, false);
        stack<int> s;
        s.push(start);

        cout << "DFS traversal: ";
        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited[node]) {
                cout << node << " ";
                visited[node] = true;

                // Push neighbors in reverse for consistent ordering
                for (int i = adj[node].size() - 1; i >= 0; i--) {
                    int neighbor = adj[node][i];
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int V = 6;  // Number of nodes
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.bfs(0);
    g.dfs(0);

    return 0;
}
