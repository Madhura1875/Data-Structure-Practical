#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int findP(int v, vector<int>& parent) {
    if (parent[v] == v) return v;
    return parent[v] = findP(parent[v], parent);
}

void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findP(a, parent);
    b = findP(b, parent);
    if (a != b) {
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

int main() {
    int n, e;
    cout << "Enter nodes: ";
    cin >> n;

    cout << "Enter edges (u v w): ";
    cin >> e;

    vector<Edge> edges;

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), 
         [](Edge a, Edge b){ return a.w < b.w; });

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    int cost = 0;
    cout << "\nKruskal MST:\n";

    for (auto &ed : edges) {
        if (findP(ed.u, parent) != findP(ed.v, parent)) {
            cout << ed.u << " - " << ed.v << " : " << ed.w << endl;
            cost += ed.w;
            unionSet(ed.u, ed.v, parent, rank);
        }
    }

    cout << "Total cost = " << cost << endl;

    return 0;
}

