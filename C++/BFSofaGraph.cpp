#include <bits/stdc++.h>
using namespace std;

/*
Breadth-First Search (BFS) of a graph
Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/

vector<int> bfs(int n, int src, const vector<vector<int>>& adj) {
    vector<int> visited(n, 0);
    vector<int> order;
    queue<int> q;
    visited[src] = 1;
    q.push(src);

    while (!q.empty()) {
        int node = q.front(); q.pop();
        order.push_back(node);
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = 1;
                q.push(neigh);
            }
        }
    }
    return order;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m; // number of vertices and edges
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // remove this line for directed graph
    }

    int src; cin >> src; // starting vertex for BFS
    auto order = bfs(n, src, adj);

    // Print BFS traversal
    for (int i = 0; i < order.size(); ++i) 
        cout << order[i] << (i+1==order.size()?'\n':' ');

    return 0;
}
