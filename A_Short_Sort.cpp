#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin>>t;
    while(t--) {
        string a; cin>>a;
        int ok = 0;
        for(int i = 0;i<3;i++) {
            if (a[i] != "abc"[i]) ok++;
        }
        if (ok == 0 || ok == 2) cout << "YES" << endl;
        else cout << "NO" << endl; 
    }
}