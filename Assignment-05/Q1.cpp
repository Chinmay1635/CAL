#include <iostream>
using namespace std;

long long calculateConnections(long long n) {
    return (n * (n - 1)) / 2;
}

int main() {
    long long A, B;
    cin >> A >> B;

    long long maxHousesInOneLocality = A - B + 1;
    long long maxConnections = calculateConnections(maxHousesInOneLocality);

    long long minHousesPerLocality = A / B;
    long long extraHouses = A % B;

    long long minConnections = (B - extraHouses) * calculateConnections(minHousesPerLocality);
    
    if (extraHouses > 0) {
        minConnections += extraHouses * calculateConnections(minHousesPerLocality + 1);
    }

    cout << "Minimum connections: " << minConnections << endl;
    cout << "Maximum connections: " << maxConnections << endl;

    return 0;
}