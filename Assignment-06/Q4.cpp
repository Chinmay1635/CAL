#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item { string name; int w; double v; bool indiv; };

int main() {
    int C, n;
    cout << "Enter knapsack capacity and number of items: ";
    cin >> C >> n;
    vector<Item> a(n);
    cout << "Enter item details (name weight value indivisible[1/0]) for each item:\n";
    for (int i = 0; i < n; i++) {
        int ind;
        cin >> a[i].name >> a[i].w >> a[i].v >> ind;
        a[i].indiv = (ind == 1);
    }
    sort(a.begin(), a.end(), [](Item &x, Item &y) {
        return (x.v / x.w) > (y.v / y.w);
    });

    double val = 0;
    int rem = C;
    for (auto &it : a) {
        if (rem <= 0) break;
        if (it.indiv) {
            if (it.w <= rem) { val += it.v; rem -= it.w; }
        } else {
            int take = min(rem, it.w);
            val += (it.v / it.w) * take; rem -= take;
        }
    }
    cout << "Total value=" << val << " Remaining cap=" << rem << "\n";
    return 0;
}
