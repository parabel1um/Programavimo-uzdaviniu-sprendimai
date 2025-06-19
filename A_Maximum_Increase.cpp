#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n;cin>>n;
    vector<ll> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    int maxK=1, k=1;
    for(int i=1;i<n;i++){
        if(A[i]>A[i-1]) k++;
        else {
            k=1;
        }
        maxK=max(maxK, k); //turi būti čia, nes jeigu paskutinis elementas ĮSIDEMĖTI DRIABNT SU PREV
    }
    cout<<maxK<<endl;
}