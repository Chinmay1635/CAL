#include <iostream>
#include <vector>
using namespace std;

int findMaxBitonic(vector<int>& arr, int n) {
    int low=0,high=n-1;
    while(low<=high) {
        int mid=low+(high-low)/2;

        if(mid > 0 && mid < n-1) {
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return arr[mid];
            else if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1])
                low = mid + 1;
            else
                high = mid - 1;
        }
        else if(mid == 0) {
            return arr[0] > arr[1] ? arr[0] : arr[1];
        }
        else if(mid == n-1) {
            return arr[n-1] > arr[n-2] ? arr[n-1] : arr[n-2];
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i=0;i<n;i++) cin >> arr[i];
    
    cout << "Maximum element = " << findMaxBitonic(arr, n) << endl;
    return 0;
}
