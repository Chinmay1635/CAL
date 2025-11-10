#include <bits/stdc++.h>
using namespace std;

 bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows=matrix.size();
        int cols=matrix[0].size();
        int low = 0, high = cols - 1;

        while (low < rows && high >= 0) {
            if (matrix[low][high] == target){
              return true;  
            } 
            else if (matrix[low][high] > target){
             high--;
            }
            else{
             low++;
            }
            }

    return false;
    }

int main(){
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50},
        {60, 61, 62, 63}
    };
    int target = 0;
    bool result = searchMatrix(matrix, target);
    cout << "Target " << target << (result ? " found." : " not found.") << endl;
    return 0;
}