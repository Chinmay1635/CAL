// Problem 2: Minimum elevator rides (bitmask DP), n <= 20
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; long long x;
    if (!(cin >> n >> x)) return 0;
    vector<long long> w(n);
    for (int i = 0; i < n; ++i) cin >> w[i];

    const int FULL = 1 << n;
    // dp[mask] = pair<rides, weight_in_last_ride>
    const int INF_R = n + 5;
    vector<pair<int, long long>> dp(FULL, {INF_R, 0});
    dp[0] = {1, 0}; // start with 1 ride with weight 0

    for (int mask = 0; mask < FULL; ++mask) {
        auto cur = dp[mask];
        if (cur.first == INF_R) continue; // unreachable
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) continue;
            int nm = mask | (1 << i);
            pair<int, long long> cand = cur;
            if (cand.second + w[i] <= x) cand.second += w[i];
            else { cand.first += 1; cand.second = w[i]; }
            // lexicographic min: smaller rides, or same rides but smaller last weight
            if (cand.first < dp[nm].first || (cand.first == dp[nm].first && cand.second < dp[nm].second)) {
                dp[nm] = cand;
            }
        }
    }

    cout << dp[FULL - 1].first << '\n';
    return 0;
}
