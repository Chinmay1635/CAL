#include <iostream>
#include <vector>

using namespace std;

int main(){
    int workload[] = {3,5,6,8,9,5,7};
    int n=7;

    int ans=0;

    int i=0;
    for(i=0; i<n; i++){
        int days=0;
        for(int j=i; j<n; j++){
            if(workload[j]>6){
                days++;
            }else{
                i=j+1;
                ans=max(ans,days);
            }
        }
    }

    cout<<"Answer is:" << ans <<endl;

}
