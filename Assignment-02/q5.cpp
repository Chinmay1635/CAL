#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
   int arr[] = {1001,1002,1004,1005};
    int curr = arr[0];
    int i = 0;
    while(i<n && arr[i] == curr) {
        i++;
        curr++;
    }
    if(i == n) {
        cout << "No Item Is Missing" << endl;
    }
    else{
        cout << "Item Missing Has Timestamp: " << curr << endl;
    }
}