#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, t;cin>>n>>t;
    vector<int> A(n-1);
    for(int i=0;i<n-1;i++) cin>>A[i];
    int curr=1+A[0];
    while(curr<t) curr+=A[curr-1]; //sita isdemeti
    if(curr==t) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}