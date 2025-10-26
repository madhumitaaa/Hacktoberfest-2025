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

    // Example usage:
    // n = number of vertices (0..n-1), m = number of edges
    // Input format example:
    // 5 6
    // 0 1
    // 0 2
    // 1 2
    // 1 3
    // 2 3
    // 3 4
    // src = 0

    int n, m;
    if (!(cin >> n >> m)) {
        // Fallback demo graph if no input provided
        n = 5; m = 6;
        vector<pair<int,int>> edges = {
            {0,1},{0,2},{1,2},{1,3},{2,3},{3,4}
        };
        vector<vector<int>> adj(n);
        for (auto [u,v] : edges) {
            adj[u].push_back(v);
            adj[v].push_back(u); // comment out for directed graph
        }
        int src = 0;
        auto order = bfs(n, src, adj);
        for (int i = 0; i < order.size(); ++i) cout << order[i] << (i+1==order.size()?'\n':' ');
        return 0;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // comment out for directed graph
    }
    int src; cin >> src;
    auto order = bfs(n, src, adj);
    for (int i = 0; i < order.size(); ++i) cout << order[i] << (i+1==order.size()?'\n':' ');

    return 0;
}
