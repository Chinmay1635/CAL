#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Node {
    string s; int f; Node *l, *r;
    Node(string s, int f) : s(s), f(f), l(0), r(0) {}
    Node(Node *a, Node *b) : s(""), f(a->f + b->f), l(a), r(b) {}
};
struct cmp { bool operator()(Node *a, Node *b) { return a->f > b->f; } };

void dfs(Node *root, string code, map<string, string> &res) {
    if (!root->l && !root->r) { res[root->s] = code; return; }
    if (root->l) dfs(root->l, code + "0", res);
    if (root->r) dfs(root->r, code + "1", res);
}

int main() {
    int n;
    cout << "Enter number of symbols: ";
    cin >> n;
    priority_queue<Node *, vector<Node *>, cmp> pq;
    vector<pair<string, int>> arr(n);
    cout << "Enter symbol and frequency for each symbol:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        pq.push(new Node(arr[i].first, arr[i].second));
    }
    while (pq.size() > 1) {
        auto a = pq.top(); pq.pop();
        auto b = pq.top(); pq.pop();
        pq.push(new Node(a, b));
    }
    Node *root = pq.top();
    map<string, string> codes; dfs(root, "", codes);
    cout << "Codes:\n";
    for (auto &p : arr) cout << p.first << ":" << codes[p.first] << "\n";
    return 0;
}
