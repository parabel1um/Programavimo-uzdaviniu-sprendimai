#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, q, sum = 0;
    cin >> n >> q;

    vector<long long> a(n);
    vector<long long> dazn(n + 1, 0);


    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r;

        cin >> l >> r;
        l--;
        r--;
        dazn[l]++;  
        if (r + 1 < n) dazn[r + 1]--; 
    }

    for (int i = 1; i < n; i++) {
        dazn[i] += dazn[i - 1];
    }

    dazn.pop_back();

    sort(dazn.rbegin(), dazn.rend());
    sort(a.rbegin(), a.rend());

    for (int i = 0; i< n; i++) {
        sum += a[i] * dazn[i];
    }
    
    cout << sum << endl;



}
