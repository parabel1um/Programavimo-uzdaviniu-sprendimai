#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x, sum = 0;
        cin >> n >> x;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        if (sum % x != 0) {
            cout << n << endl;
            continue;
        }
        
        int kair = -1, des = -1;

        for (int i=0;i<n;i++) {
            if (a[i] % x != 0) {
                kair = i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (a[i] % x != 0) {
                des = i;
                break;
            }
        }

        int maxIlg = -1;
        if (kair != -1) {
            maxIlg = max(maxIlg, n-kair-1);
        }
        if (des != -1) {
            maxIlg = max(maxIlg, des);
        }

        cout << (maxIlg != -1 ? maxIlg : -1) << endl;

    }
}