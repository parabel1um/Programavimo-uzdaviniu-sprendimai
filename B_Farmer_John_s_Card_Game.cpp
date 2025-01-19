#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    const int N = 2005; 
    int n, m, ans[N], NEXT[N];
    set<int> a[N];
    bool A[N];

    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < n; i++) a[i].clear();
        
        for (int i = 0; i < N; i++) {
            NEXT[i] = -1;
            A[i] = false;
        }

        for (int i = 0; i < n; i++) {
            int x;
            for (int j = 0; j < m; j++) {
                cin >> x;
                a[i].insert(x); 
            }
            NEXT[*a[i].begin()] = i; 
        }

        int k = n * m;
        bool valid = true;

        for (int i = 0; i < k; i++) {
            if (i < n) {
                if (NEXT[i] == -1) {
                    valid = false;
                    break;
                }

                ans[i] = NEXT[i];
                a[NEXT[i]].erase(a[NEXT[i]].begin()); 
                if (!a[NEXT[i]].empty()) {
                    NEXT[*a[NEXT[i]].begin()] = NEXT[i];
                }

                if (A[NEXT[i]]) {
                    valid = false;
                    break;
                }
                A[NEXT[i]] = true;
            } else {
                if (NEXT[i] == -1 || ans[i % n] != NEXT[i]) {
                    valid = false;
                    break;
                }

                a[NEXT[i]].erase(a[NEXT[i]].begin());
                if (!a[NEXT[i]].empty()) {
                    NEXT[*a[NEXT[i]].begin()] = NEXT[i];
                }
            }
        }

        if (valid) {
            for (int i = 0; i < n; i++) {
                cout << ans[i] + 1 << ' '; 
            }
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}