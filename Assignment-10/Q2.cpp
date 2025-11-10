#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c, int n) {
    for (int i = 0; i < n; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& color, int v, int n) {
    if (v == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, n)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1, n))
                return true;
            color[v] = 0; // backtrack
        }
    }
    return false;
}

void graphColoring(vector<vector<int>>& graph, int n) {
    vector<int> color(n, 0);
    int m = 1;
    while (true) {
        if (graphColoringUtil(graph, m, color, 0, n)) {
            cout << "Minimum Colors Required: " << m << endl;
            cout << "Color Assignment:\n";
            for (int i = 0; i < n; i++)
                cout << "Vertex " << i << " ---> Color " << color[i] << endl;
            break;
        }
        m++; // try with more colors
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    graphColoring(graph, n);
    return 0;
}
