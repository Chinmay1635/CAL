#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int C, n;
    cout << "Enter capacity and number of luggage items: ";
    cin >> C >> n;
    vector<int> w(n);
    cout << "Enter weights of luggage: ";
    for (int i = 0; i < n; ++i) cin >> w[i];
    sort(w.begin(), w.end());

    int total = 0;
    vector<int> chosen;
    for (int wt : w) {
        if (total + wt <= C) {
            total += wt;
            chosen.push_back(wt);
        }
    }
    cout << "Total loaded=" << total << "\nFamilies' luggage:\n";
    for (int wt : chosen) cout << wt << " ";
    cout << endl;
    return 0;
}
