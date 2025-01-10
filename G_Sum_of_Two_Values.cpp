#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> a(n);
    unordered_map<int, int> m;
    for (int i=0;i<n;++i) cin>>a[i];
    for (int i=0;i<n;++i) {
        if(m.find(sum - a[i]) != m.end()) {
            cout << m[sum-a[i]]+1 << " " << i + 1 << endl;
            return 0;
        }
        m[a[i]] = i;
    }
    cout<<-1<<endl;
    return 0;
}