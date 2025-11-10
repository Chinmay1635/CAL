#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of insertions: ";
    cin >> n;

    int capacity = 1;
    int total_cost = 0;

    cout << left << setw(10) << "Operation"
         << setw(15) << "Actual Cost"
         << setw(15) << "Total Cost"
         << setw(15) << "Amortized Cost" << endl;

    for (int i = 1; i <= n; i++) {
        int cost = 0;
        if (i > capacity) {
            capacity *= 2;
            cost = i;  // cost = copies + new insert
        } else {
            cost = 1;
        }
        total_cost += cost;

        double amortized = (double) total_cost / i;

        cout << left << setw(10) << ("Insert " + to_string(i))
             << setw(15) << cost
             << setw(15) << total_cost
             << setw(15) << fixed << setprecision(2) << amortized
             << endl;
    }

    return 0;
}
