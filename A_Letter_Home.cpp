#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, s;
        cin>>n>>s;
        vector<int> A(n);
        for(int i=0;i<n;i++) cin>>A[i];
        int beg = A[0], end = A[n - 1];
        cout<<(end-beg) + min(abs(s-beg), abs(s-end))<<endl;
    }
    return 0;
}
