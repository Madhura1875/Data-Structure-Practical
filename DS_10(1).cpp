#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int v, vector<int>& parent) {
    if (parent[v] == v) return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) {
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int adj[20][20];
    cout << "Enter adjacency matrix (0 if no edge):\n";

    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
            if (adj[i][j] != 0 && i < j) {
                edges.push_back({i, j, adj[i][j]});
            }
        }
    }

    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) { return a.w < b.w; });

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    int cost = 0;
    cout << "\nEdges in MST:\n";

    for (auto &e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            cout << e.u << " - " << e.v << " : " << e.w << endl;
            cost += e.w;
            unionSet(e.u, e.v, parent, rank);
        }
    }

    cout << "Total Minimum Cost: " << cost << endl;

    return 0;
}

