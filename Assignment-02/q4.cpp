#include <bits/stdc++.h>
using namespace std;

int main() {
    long long X, Y, s, T;
    cin >> X >> Y >> s >> T;

    long long count = 0;


    for (long long x = X; x <= X + s; x++) {
        for (long long y = Y; y <= Y + s; y++) {
            if (x >= 0 && y >= 0 && x + y <= T) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
