#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k=0;cin>>n;
    vector<int> A(n);//boys
    for(int i=0;i<n;i++) cin>>A[i];
    int m;cin>>m;
    vector<int> B(m);
    for(int i=0;i<m;i++) cin>>B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    //two pointer nereikia nes ieškome tik vienos reikšmės, ir mums reikia kai kurius skaičius ištrinti
    int l=0;
    for(int i=0;i<n&&l<m;i++) {
        while(abs(B[l]-A[i])>1) {
            if(B[l]<A[i]) l++;
            else break;
        }
        if(abs(B[l]-A[i])<=1) l++, k++;
    }
    cout<<k<<endl;
}
