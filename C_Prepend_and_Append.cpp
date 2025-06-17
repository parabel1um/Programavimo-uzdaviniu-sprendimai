#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;cin>>t;
    while(t--) {
        int n; cin>>n;
        string a;cin>>a;
        int l=0, r=n-1;
        while(l<=r) {
            if(a[l]!=a[r]) {
                r--;l++;
                n-=2;
            } else break;
        }
        cout<<n<<endl;
    }
}