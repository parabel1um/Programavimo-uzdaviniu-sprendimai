#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() 
{
    int t; 
    cin >> t; 
    while(t--) {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2; 
        ll kn = 1; 
        ll ans = 0; 

        for(int n = 0; r2 / kn >= l1; n++) {
            ll min_x = max((l2-1) / kn + 1, l1);
            ll max_x = min(r2 / kn, r1);
            ans += max(0ll, max_x - min_x + 1); 
            kn *= k; 
        }

        cout << ans << '\n'; 
    }
    return 0;
}