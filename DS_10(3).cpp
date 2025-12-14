#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

class Graph {
    int n;
    vector<pii> adj[20];

public:
    Graph(int nodes) { n = nodes; }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void prim() {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> visited(n, 0);

        pq.push({0, 0});
        int cost = 0;

        cout << "\nEdges in MST:\n";

        while (!pq.empty()) {
            int w = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = 1;
            cost += w;

            if (u != 0)
                cout << "Node " << u << " included with weight " << w << endl;

            for (auto &p : adj[u]) {
                pq.push({p.second, p.first});
            }
        }

        cout << "Total cost = " << cost << endl;
    }
};

int main() {
    int n, e;
    cout << "Enter nodes: ";
    cin >> n;

    Graph g(n);

    cout << "Enter edges (u v w): ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.prim();
}

