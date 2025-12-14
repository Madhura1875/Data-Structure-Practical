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

    void dijkstra(int src) {
        vector<int> dist(n, 1e9);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for (auto &p : adj[u]) {
                int v = p.first;
                int w = p.second;

                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "\nShortest distances:\n";
        for (int i = 0; i < n; i++)
            cout << src << " -> " << i << " = " << dist[i] << endl;
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

    g.dijkstra(0);
}

