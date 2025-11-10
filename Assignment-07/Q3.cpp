// Problem 3: Domino Solitaire (2xN) — DP O(N)
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    vector<vector<int>> a(2, vector<int>(N));
    for (int r = 0; r < 2; ++r)
        for (int i = 0; i < N; ++i)
            cin >> a[r][i];

    // dp[i] = max score covering first i columns (0..i-1)
    const long long NEG = LLONG_MIN / 4;
    vector<long long> dp(N + 1, NEG);
    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
        // Option 1: vertical tile at column i-1
        long long vert = llabs((long long)a[0][i-1] - a[1][i-1]);
        dp[i] = max(dp[i], dp[i-1] + vert);

        // Option 2: two horizontal tiles covering columns i-2 and i-1
        if (i >= 2) {
            long long top = llabs((long long)a[0][i-2] - a[0][i-1]);
            long long bot = llabs((long long)a[1][i-2] - a[1][i-1]);
            dp[i] = max(dp[i], dp[i-2] + top + bot);
        }
    }

    cout << dp[N] << '\n';
    return 0;
}
