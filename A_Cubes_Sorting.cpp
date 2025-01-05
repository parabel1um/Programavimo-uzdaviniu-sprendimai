#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool s = false;
        for (int i = 0; i < n-1; i++) {
            if (a[i] <= a[i + 1]) {
                s = true;
                break;
            }
        }
        cout << (s ? "YES" : "NO") << endl;
    }

    return 0;
}