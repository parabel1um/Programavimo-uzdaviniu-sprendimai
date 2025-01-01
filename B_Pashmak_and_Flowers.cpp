#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n, m = 0;

    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    long long maxim = *max_element(a.begin(), a.end());
    long long minim = *min_element(a.begin(), a.end());

    long long maxN = count(a.begin(), a.end(), maxim);
    long long minN = count(a.begin(), a.end(), minim);

    if (maxim != minim) cout << maxim - minim << " " << maxN * minN << endl;
    else {
        long long w = (long long)n * (n - 1) / 2;
        cout << 0 << " " << w << endl;
    }
    
}