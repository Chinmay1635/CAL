#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int largestSubarrayWithXDistinctAndY(int N, int X, int Y, const vector<int>& A) {
    map<int, int> freq;  
    int start = 0, max_len = -1, distinct_count = 0;
    
    for (int end = 0; end < N; ++end) {
        if (freq[A[end]] == 0) {
            distinct_count++;
        }
        freq[A[end]]++;
        
        while (distinct_count > X) {
            freq[A[start]]--;
            if (freq[A[start]] == 0) {
                distinct_count--;
            }
            start++;
        }
        
        if (distinct_count == X && freq[Y] > 0) {
            max_len = max(max_len, end - start + 1);
        }
    }
    
    return max_len;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, X, Y;
        cin >> N >> X >> Y;
        
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        
        int result = largestSubarrayWithXDistinctAndY(N, X, Y, A);
        cout << result << endl;
    }
    
    return 0;
}