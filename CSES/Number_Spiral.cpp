#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t; cin>>t;
    while(t--) {
        ll y,x,ans; cin>>y>>x;
        ll n=max(y, x); //randame, kuri koordinate yra didesne, nes tik toje eiluteje arba stulpelyje bus atsakymas
        if (n%2==0) { // lyginis x arba y
            if (y==n) {
                ans=n*n-x+1;
            } else {
                ans=(n-1)*(n-1)+y;
            }
        } else {//nelyginis x arba y
            if (x==n) {
                ans=n*n-y+1;
            } else {
                ans=(n-1)*(n-1)+x;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}
