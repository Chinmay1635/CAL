#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int oddCount = 0, evenCount = 0;
    vector<int> costs;

    for (int i = 0; i < N - 1; i++) {
        if (arr[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;

        if (oddCount == evenCount) {
            costs.push_back(abs(arr[i] - arr[i + 1]));
        }
    }

    sort(costs.begin(), costs.end());

    int totalCost = 0, maxPartitions = 0;
    for (int i = 0; i < costs.size(); i++) {
        if (totalCost + costs[i] <= K) {
            totalCost += costs[i];
            maxPartitions++;
        } else {
            break;
        }
    }

    cout << "Maximum number of separations: " << maxPartitions << endl;
    return 0;
}