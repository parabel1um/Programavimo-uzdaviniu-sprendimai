#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, ok=0; cin>>n;
    vector<char> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    char prev='k';
    for(int i=0;i<n;i++) {
        if(a[i]==prev) ok++;
        prev=a[i];
    }
    cout << ok<< endl;
}