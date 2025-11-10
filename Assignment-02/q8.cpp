#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

signed main() {
    int n;
    cout<<"Enter n"<<endl;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i = 0;
    int ans = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n && a[j] < a[j - 1]) {
            j++;
        }
        if(j-i>=3) ans += 1;
        i = j;
    }
    cout << ans << endl;
    return 0;
}