#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job { int id, d, p; };

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    vector<Job> jobs(n);
    int maxD = 0;
    cout << "Enter job details (id deadline profit) for each job:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].d >> jobs[i].p;
        maxD = max(maxD, jobs[i].d);
    }
    vector<int> slot(maxD + 1, -1);
    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) { return a.p > b.p; });

    int profit = 0;
    for (auto &j : jobs) {
        for (int t = j.d; t > 0; t--) {
            if (slot[t] == -1) { slot[t] = j.id; profit += j.p; break; }
        }
    }
    cout << "Max profit=" << profit << "\nJobs scheduled:\n";
    for (int i = 1; i <= maxD; i++)
        if (slot[i] != -1) cout << "Slot " << i << ": J" << slot[i] << "\n";
    return 0;
}
