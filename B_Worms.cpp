#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> a(n), prefix(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        prefix[i] = (i == 0 ? a[i] : prefix[i - 1] + a[i]);
    }

    cin >> m;
    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++) {
        int worm = b[i];

        int pile = lower_bound(prefix.begin(), prefix.end(), worm) - prefix.begin();;
        
        cout << pile + 1 << endl;
    }

    return 0;
}
