#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll sub(const vector<ll>& A,ll sum, ll limitas) {
    unordered_map<ll, ll> freq; // tik indexams
    freq[0]=1;
    ll prefSum=0, k=0;

    for (ll val : A) {
        if (val>limitas) {
            prefSum=0;
            freq.clear();
            freq[0]=1;
            continue;
        }
        prefSum+=val;
        ll m=prefSum-sum;
        if (freq.count(m)) {
            k+=freq[m];
        }
        freq[prefSum]++;
    }

    return k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while (t--) {
        int l;
        ll sum, did;
        cin>>l>>sum>>did;
        vector<ll> A(l);
        for (int i=0;i<l;i++) cin>>A[i];
        ll ans=sub(A,sum,did) - sub(A,sum,did - 1);
        cout<<ans<<endl;
    }
    return 0;
}
