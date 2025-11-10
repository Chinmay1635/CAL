#include <iostream>
#include <vector>

using namespace std;

int main(){
   int n,k;
   cout<<"Enter n and k"<<endl;
   cin >> n >> k;
   int remaining = k%n;
   int round = k/n;
   if(round==0){
    cout<<remaining<<endl;
   }else{
    cout<<n-remaining<<endl;
   }

}
