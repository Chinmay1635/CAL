#include <bits/stdc++.h>
using namespace std;

 int search(vector<int>& nums, int target) {
        
        int n = nums.size();

        int low = 0;
        int high = n-1;
        while(low<high){
            int mid = low+(high-low)/2;
             if(nums[mid]>nums[high]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
              int pivot = high;
        low=0;
        high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int real = (mid+pivot)%n;
            if(nums[real]==target){
                return real;
            }else if(nums[real]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return -1;

    }


int main(){
    vector<int>nums = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    int target = 5;
    int result = search(nums, target);
    cout << "Index of target " << target << " is: " << result << endl;
    return 0;
}