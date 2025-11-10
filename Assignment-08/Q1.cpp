#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int to;
    int w;
};

int dijkstra(int n, vector<vector<Edge>>& adj, int src, int dest) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (u == dest) return d; // Early stop if destination reached
        if (d > dist[u]) continue;
        
        for (auto& e : adj[u]) {
            int v = e.to, w = e.w;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return INF;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<tuple<int, int, int>> edges;
    int maxNode = 0;
    
    for (int i = 0; i < N; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        maxNode = max({maxNode, u, v});
    }
    
    vector<vector<Edge>> adj(maxNode + 1);
    for (auto [u, v, w] : edges) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    int minCycle = INF;
    
    for (auto [u, v, w] : edges) {
        // Temporarily remove edge (u, v)
        auto removeEdge = [&](int a, int b) {
            adj[a].erase(remove_if(adj[a].begin(), adj[a].end(), 
                [&](Edge e){ return e.to == b; }), adj[a].end());
        };
        
        removeEdge(u, v);
        removeEdge(v, u);
        
        // Find shortest path from u to v
        int shortest = dijkstra(maxNode, adj, u, v);
        
        if (shortest != INF)
            minCycle = min(minCycle, shortest + w);
        
        // Reinsert edge
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    cout << minCycle << "\n";
    return 0;
}
