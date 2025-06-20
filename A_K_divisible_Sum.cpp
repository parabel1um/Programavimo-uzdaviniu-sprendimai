#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while (t--) {
        ll n, k;cin>>n>>k;
        double sum = ceil((double)n/k)*k; // get the average, multiply it - get the sum
        double ans = ceil(sum/n); // divide the sum by amount of numbers
        cout<<(ll)ans<<"\n";
    }

    return 0;
}
