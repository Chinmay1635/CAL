#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> longestTower(vector<pair<int, int>> people) {
    int n = people.size();
    

    sort(people.begin(), people.end());

    
    vector<int> dp(n, 1);         
    vector<int> parent(n, -1);    
    int maxLen = 1, lastIndex = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (people[j].second < people[i].second && 
                people[j].first < people[i].first && 
                dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            lastIndex = i;
        }
    }

    vector<pair<int,int>> result;
    while (lastIndex != -1) {
        result.push_back(people[lastIndex]);
        lastIndex = parent[lastIndex];
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<pair<int, int>> people = {
        {65, 100}, {70, 150}, {56, 90},
        {75, 190}, {60, 95}, {68, 110}
    };

    vector<pair<int, int>> tower = longestTower(people);

    cout << "The longest tower is length " << tower.size() << " and includes (from top to bottom):\n";
    for (auto &p : tower) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
