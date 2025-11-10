#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Building {
    int left, height, right;
};

int main() {
    int n;
    cout << "Enter number of buildings: ";
    cin >> n;

    vector<Building> buildings(n);
    for(int i=0;i<n;i++) {
        cin >> buildings[i].left >> buildings[i].height >> buildings[i].right;
    }

    vector<pair<int,int>> events; 
    for(auto &b : buildings) {
        events.push_back({b.left, -b.height});  
        events.push_back({b.right, b.height});  
    }

    sort(events.begin(), events.end());

    multiset<int> heights;
    heights.insert(0);
    int prevMax = 0;

    vector<pair<int,int>> result;

    for(auto &e : events) {
        int x = e.first, h = e.second;

        if(h < 0) {
            heights.insert(-h);
        } else { 
            heights.erase(heights.find(h));
        }

        int currMax = *heights.rbegin();
        if(currMax != prevMax) {
            result.push_back({x, currMax});
            prevMax = currMax;
        }
    }

    cout << "Skyline: ";
    for(auto &p : result) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    return 0;
}
