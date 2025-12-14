#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int n;
    vector<int> adj[20];

public:
    Graph(int nodes) { n = nodes; }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int start) {
        vector<bool> visited(n, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "\nBFS: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v : adj[u])
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
        }
    }

    void DFSUtil(int u, vector<bool> &visited) {
        visited[u] = true;
        cout << u << " ";

        for (int v : adj[u])
            if (!visited[v])
                DFSUtil(v, visited);
    }

    void DFS(int start) {
        vector<bool> visited(n, false);
        cout << "\nDFS: ";
        DFSUtil(start, visited);
    }
};

int main() {
    int n, e;
    cout << "Nodes: ";
    cin >> n;

    Graph g(n);

    cout << "Edges: ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.BFS(0);
    g.DFS(0);

    return 0;
}

