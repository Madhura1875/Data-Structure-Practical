#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
    int n;
    int adj[20][20];

public:
    Graph(int nodes) {
        n = nodes;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = 0;
    }

    void addEdge(int u, int v) {
        adj[u][v] = adj[v][u] = 1;
    }

    void BFS(int start) {
        vector<bool> visited(n, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "\nBFS Traversal: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int i = 0; i < n; i++) {
                if (adj[node][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void DFSUtil(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < n; i++)
            if (adj[v][i] == 1 && !visited[i])
                DFSUtil(i, visited);
    }

    void DFS(int start) {
        vector<bool> visited(n, false);
        cout << "\nDFS Traversal: ";
        DFSUtil(start, visited);
    }
};

int main() {
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;

    Graph g(n);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.BFS(0);
    g.DFS(0);

    return 0;
}

