#include <bits/stdc++.h>
using namespace std;

int main() {
    int n=10,target=10;
    int nums[]={6,7,9,2,3,1,4,2,5,0};
    int idx = -1;
    for(int i = 0 ; i<n ; i++){
        if(nums[i] == target){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index: " << idx << endl;
    }
    return 1;
}