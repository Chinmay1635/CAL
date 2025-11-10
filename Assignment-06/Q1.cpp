// Simple MST Algorithms Example
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Edge structure: connects node u and v with weight w
struct Edge {
    int u, v;
    long long w;
};

// Disjoint Set Union (for Kruskal)
class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) return false;
        if (rank[rootA] < rank[rootB]) swap(rootA, rootB);
        parent[rootB] = rootA;
        if (rank[rootA] == rank[rootB]) rank[rootA]++;
        return true;
    }
};

// Kruskal's Algorithm
pair<vector<Edge>, long long> kruskal(int n, vector<Edge> edges) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });
    DSU dsu(n);
    vector<Edge> mst;
    long long totalWeight = 0;
    for (Edge &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            totalWeight += e.w;
            if ((int)mst.size() == n - 1) break;
        }
    }
    return {mst, totalWeight};
}

// Prim's Algorithm
pair<vector<Edge>, long long> prim(int n, vector<vector<pair<int, long long>>> &adj, int start = 0) {
    vector<bool> visited(n, false);
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
    visited[start] = true;
    for (auto &pr : adj[start]) {
        pq.push({pr.second, start, pr.first});
    }
    vector<Edge> mst;
    long long totalWeight = 0;
    while (!pq.empty() && (int)mst.size() < n - 1) {
        auto [w, u, v] = pq.top(); pq.pop();
        if (visited[v]) continue;
        visited[v] = true;
        mst.push_back({u, v, w});
        totalWeight += w;
        for (auto &pr : adj[v]) {
            if (!visited[pr.first]) pq.push({pr.second, v, pr.first});
        }
    }
    return {mst, totalWeight};
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    if (!(cin >> n >> m)) {
        cout << "Input format: n m followed by m lines: u v w (0-based indices)\n";
        return 0;
    }
    vector<Edge> edges;
    vector<vector<pair<int, long long>>> adj(n);
    cout << "Enter each edge (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v; long long w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    auto [kruskalMST, kruskalWeight] = kruskal(n, edges);
    cout << "\nKruskal's MST total weight: " << kruskalWeight << "\n";
    cout << "Edges (u v w):\n";
    for (auto &e : kruskalMST) cout << e.u << " " << e.v << " " << e.w << "\n";

    auto [primMST, primWeight] = prim(n, adj, 0);
    cout << "\nPrim's MST total weight: " << primWeight << "\n";
    cout << "Edges (u v w):\n";
    for (auto &e : primMST) cout << e.u << " " << e.v << " " << e.w << "\n";

    return 0;
}
