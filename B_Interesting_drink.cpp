#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, m; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    };
    cin>>m;
    sort(a.begin(), a.end());
    for(int i=0;i<m;i++) {
        int y; cin>>y;
        cout<<upper_bound(a.begin(), a.end(), y) - a.begin()<<endl;
    }
}