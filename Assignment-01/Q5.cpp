#include<bits/stdc++.h>
using namespace std;
 
int solve(vector<string>& v, string to_find) {
    for(int i=0;i<v.size();i++) {
    if(to_find==v[i]) {
        return i+1;
    }
}

return -1;
}

int main() {

vector<string> v = {"at","","","ball","","","car","","","dad","",""};
string to_find = "ball";

int ans = solve(v,to_find);
cout<<ans<<endl;
 
return 0;
 
}