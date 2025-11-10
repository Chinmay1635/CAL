#include <bits/stdc++.h>
using namespace std;

int main() {
    int n=10,target=100;
    int nums[]={1,1,3,5,8,9,10,14,16,20};
    int s = 0;
    int e = n-1;
    int mid = s+(e-s)/2;
    while(s <= e) {
        if(nums[mid] == target) {
            cout << "Element found at index: " << mid << endl;
            return 0;
        } else if(nums[mid] < target) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    cout << "Element not found" << endl;
    return 0;
}