#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi  vector<int>
#define vss vector<string>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vpp(T1, T2) vector<pair<T1, T2>>

ll llPow(ll a, ll b) { // a skaičius, b laipsnis
    ll res =1;
    while(b>0) {
        if(b&1) res*=a; // jeigu skaičius odd
        a*=a; // vienu laipsniu pakeliame ^2
        b>>=1; // same as b/2
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        ll sum = n*(n+1)/2;

        // turime sužinoti kiek yra 2^k skaičių iki n;
        ll k=0;
        while(llPow(2, k)<=n) {
            sum-=llPow(2, k)*2;
            k++;
        }
        cout << sum << endl;
    }

}