#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        ll prefSum=0, deltaSum=0;
        string s;cin>>s;
        vector<ll> A(n+1);
        A[0]=0;
        for(int i=1;i<=n;i++) {
            if (s[i-1] == '0') {
                A[i] = A[i-1]+1;
            } else {
                A[i] = A[i-1]-1;
            }
        }
        sort(A.begin(), A.end());
        for (int i = 0; i <= n; i++) {
            deltaSum+=A[i]*i-prefSum;
            prefSum+=A[i];
        }
        int totalSub = n*(n+1) *(n+2)/6;
        int ans = (totalSub+deltaSum)/2;
       cout<<ans<<endl;
    }
    return 0;
}