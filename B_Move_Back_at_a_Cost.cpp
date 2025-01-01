#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10; // added 10 just to be safe
int a[maxn], b[maxn], n;

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i]; 
        }

        for (int i = n - 1; i > 0; i--) {
            b[i] = min(a[i], b[i + 1]);
        }

        int k = 1e9;
        for (int i = 1; i <= n; i++) {
            if (k < a[i] || a[i] > b[i]) {
                a[i]++;
                k = min(k, a[i]);
            }
        }

        sort(a + 1, a + n + 1);

        for (int i = 1; i <= n; i++) {
            cout << a[i] << " "; 
        }
        cout << endl;
    }
}
