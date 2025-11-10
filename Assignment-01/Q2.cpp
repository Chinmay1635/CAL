#include<bits/stdc++.h>
using namespace std;
 


void helper(vector<string>& arr) {
    unordered_map<string, vector<string>> mp;

    for (auto str : arr) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        mp[sortedStr].push_back(str);
    }

    arr.clear();
    for (auto pair : mp) {
        for (auto anagram : pair.second) {
            arr.push_back(anagram);
        }
    }
}
int main() {
    vector<string> arr = {"cat", "dog", "tac", "god", "act"};
    helper(arr);
    for (auto str : arr) {
        cout<<str<< " ";
    }
    return 0;
 
}