#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack {
    vector<int> s;
    int total_amortized_cost = 0;

public:
    void push(int x) {
        s.push_back(x);
        total_amortized_cost += 2;  // 1 actual + 1 credit saved
        cout << "Push(" << x << "): Actual Cost = 1, Amortized = 2\n";
    }

    void pop() {
        if (!s.empty()) {
            s.pop_back();
            total_amortized_cost += 0;  // use saved credit
            cout << "Pop(): Actual Cost = 1, Amortized = 0\n";
        } else {
            cout << "Pop(): Stack Empty\n";
        }
    }

    void multipop(int k) {
        int pops = min(k, (int)s.size());
        for (int i = 0; i < pops; i++) s.pop_back();
        total_amortized_cost += 0;
        cout << "Multipop(" << k << "): Actual Cost = " << pops << ", Amortized = 0\n";
    }

    void showTotal() {
        cout << "Total Amortized Cost so far = " << total_amortized_cost << endl;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.pop();
    st.multipop(2);
    st.showTotal();
    return 0;
}
