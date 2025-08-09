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
    
    int t;cin>>t;
    while(t--) {
        int n;cin>>n;
        vector<ll>A(n);
        for(int i=0;i<n;i++) cin>>A[i];
        vector<ll> B=A;
        sort(B.begin(), B.end());
        for(int i=0;i<n;i++) {
            if(A[i]!=B[n-1]) cout<<A[i]-B[n-1]<<" ";
            else cout<<A[i]-B[n-2]<<" ";
        };
        cout<<endl;
    }
}