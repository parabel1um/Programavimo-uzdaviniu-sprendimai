#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n), b;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++) {
        auto o = find(b.begin(), b.end(), a[i]);
        if (o != b.end()) b.erase(o);
        b.push_back(a[i]);
    }
    cout<<b.size()<<endl;
    for (auto i: b) cout << i << " ";
}