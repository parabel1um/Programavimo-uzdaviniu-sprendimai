#include <bits/stdc++.h>
#define ll long_long
#define ft first
#define sc second
#define mp make_pair
#define pb push_back
using namespace std;
int main () {
    int t;
    cin >> t;
    while (t--){
        int n;cin>> n;
        vector<int> a(2*n);
        for(int i = 0; i<2*n;i++) cin>>a[i];
        sort(a.begin(), a.end());
        vector<pair<int, int>>b;
        for(int i = 0; i<n;++i) {
            b.pb({a[i], a[i+n]});
        }
        int len=0;
        for(int i = 1;i<n;++i){
            len+=abs(b[i].ft - b[i-1].ft)+abs(b[i].sc-b[i-1].sc);
        }
        cout<<len<<endl;
        for(int i=0;i<n;++i){
            cout<<b[i].sc<<" "<<b[i].ft<<endl;
        }
    }
}