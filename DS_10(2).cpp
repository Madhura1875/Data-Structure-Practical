#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int adj[20][20];
    cout << "Enter adjacency matrix (0 = no connection):\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    int src;
    cout << "Enter source node: ";
    cin >> src;

    vector<int> dist(n, 1e9), visited(n, 0);
    dist[src] = 0;

    for (int k = 0; k < n; k++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0) {
                if (dist[v] > dist[u] + adj[u][v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
    }

    cout << "\nShortest distances:\n";
    for (int i = 0; i < n; i++)
        cout << src << " -> " << i << " = " << dist[i] << endl;

    return 0;
}

