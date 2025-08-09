#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi  vector<int>
#define vss vector<string>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vpp(T1, T2) vector<pair<T1, T2>>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin>>t;
    while(t--) {
        ll n,q;cin>>n>>q;
        vector<ll> a(n+1), pref(n+1, 0); // n+1 because initially index 0 is 0 value fpr the prefix
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            pref[i] = pref[i-1]+a[i];
        }

        while(q--) {
            ll l,r,k;cin>>l>>r>>k;
            ll segment = pref[r] - pref[l-1]; // total difference in sum segment
            ll newSum = pref[n] - segment + (k * (r - l + 1));
            if(newSum % 2 == 1) {
                cout<<"YES\n";
            } else {
                cout<<"NO\n";
            }
        }
    }

    return 0;
}