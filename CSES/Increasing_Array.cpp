#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;cin>>n;
    long long sum=0;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<n-1;i++) {
        if(A[i]>=A[i+1]) {
            sum+=A[i]-A[i+1];
            A[i+1]=A[i];
        }
    }
    cout<<sum<<endl;
}