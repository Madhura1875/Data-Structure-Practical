#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

class Graph {
    int n;
    vector<pii> adj[50];  // increase size if needed

public:
    Graph(int nodes) { n = nodes; }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void primMST() {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<bool> inMST(n, false);

        pq.push(make_pair(0, 0));  // weight, node

        int total = 0;

        cout << "\nEdges in MST:\n";

        while (!pq.empty()) {
            pii top = pq.top();
            pq.pop();

            int w = top.first;   // weight
            int u = top.second;  // node

            if (inMST[u]) continue;

            inMST[u] = true;
            total += w;

            if (u != 0)
                cout << "Include node: " << u << " with weight " << w << endl;

            for (size_t i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int wt = adj[u][i].second;

                if (!inMST[v]) {
                    pq.push(make_pair(wt, v));
                }
            }
        }

        cout << "Total weight of MST = " << total << endl;
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

    g.primMST();

    return 0;
}

