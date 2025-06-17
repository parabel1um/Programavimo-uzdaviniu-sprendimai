#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n;cin>>n;
        string s;cin>>s;
        unordered_map<char,int> freq;
        for(int i=0; i<n; i++) freq[s[i]]++;
        bool o=false;
        for(int i=1;i<=n-2;i++) {
            if(freq[s[i]] >= 2) {
                o=true;
                break;
            }
        }
        if(o) cout<<"YES\n"; 
        else cout<<"NO\n";
    }
}