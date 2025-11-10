#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cout << "Enter Number to Know Rank" << endl;
    cin >> x;
    bool check = false;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == x)
        {
            cout << "Rank of is " << i + 1 << endl;
            check = true;
            break;
        }
    }
    if (!check)
    {
        cout << "Number Not Found" << endl;
    }
}