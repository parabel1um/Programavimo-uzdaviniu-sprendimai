#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, sumS=0, sumD=0;cin>>n;
    bool Sereja=true;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    int l=0,r=n-1;
    while(l<=r){
        int sum=0;
        if(A[l]>A[r]) {
            sum=A[l++];
        } else {
            sum=A[r--];
        };
        if(Sereja) sumS+=sum;
        else sumD+=sum;
        Sereja=!Sereja;
    }
    cout<<sumS<<" "<<sumD<<endl;
    return 0;
}