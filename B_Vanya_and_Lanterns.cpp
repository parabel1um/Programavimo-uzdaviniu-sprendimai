#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, l;cin>>n>>l;
    double maxk=0;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    sort(A.begin(), A.end());
    for(int i=1;i<n;i++) maxk=max(maxk, (double)(A[i]-A[i-1])/2.0);
    maxk=max(maxk, (double)A[0]);
    maxk=max(maxk, (double)(l-A[n-1]));
    cout<<fixed<<setprecision(10)<<maxk<<endl;
}