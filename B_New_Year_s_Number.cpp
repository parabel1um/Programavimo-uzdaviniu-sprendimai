#include <iostream>
using namespace std;
int main() {
    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        int times2021=n%2020;
        int times2020=(n-times2021)/2020-times2021;
        if(times2021>=0&&times2020>=0&&2020*times2020+2021*times2021==n) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}