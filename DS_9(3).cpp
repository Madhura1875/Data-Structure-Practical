#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
};

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) { return a.w < b.w; }

int main() {
    int n, e;
    cout << "Enter nodes: ";
    cin >> n;
    cout << "Enter edges: ";
    cin >> e;

    vector<Edge> edges;

    for (int i = 0; i < e; i++) {
        Edge temp;
        cin >> temp.u >> temp.v >> temp.w;
        edges.push_back(temp);
    }

    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(n);
    int mstWeight = 0;

    cout << "\nEdges in MST:\n";

    for (auto &edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            cout << edge.u << " - " << edge.v << " : " << edge.w << endl;
            mstWeight += edge.w;
            dsu.unite(edge.u, edge.v);
        }
    }

    cout << "Total weight = " << mstWeight;
    return 0;
}

