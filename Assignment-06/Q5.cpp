#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cout << "Enter number of files: ";
    cin >> n;
    vector<int> files(n);
    cout << "Enter sizes of files: ";
    for (int i = 0; i < n; i++) cin >> files[i];
    priority_queue<int, vector<int>, greater<int>> pq(files.begin(), files.end());
    int cost = 0;
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        cost += a + b;
        pq.push(a + b);
    }
    cout << "Optimal merge cost=" << cost << "\n";
    return 0;
}
