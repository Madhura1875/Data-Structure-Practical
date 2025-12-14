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
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void dijkstra(int src) {
        vector<int> dist(n, 1e9);
        priority_queue<pii, vector<pii>, greater<pii> > pq;

        dist[src] = 0;
        pq.push(make_pair(0, src));

        while (!pq.empty()) {
            pii top = pq.top();
            pq.pop();

            int d = top.first;   // distance
            int u = top.second;  // node

            for (size_t i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;

                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        cout << "\nShortest distance from " << src << ":\n";
        for (int i = 0; i < n; i++)
            cout << src << " -> " << i << " = " << dist[i] << endl;
    }
};

int main() {
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;

    Graph g(n);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v w):\n";

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.dijkstra(0);

    return 0;
}

