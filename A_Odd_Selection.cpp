#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        int odd_count = 0, even_count = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) {
                even_count++;
            } else {
                odd_count++;
            }
        }

        bool possible = false;

        for (int odd_used = 1; odd_used <= odd_count && odd_used <= x; odd_used += 2) {
            int even_used = x - odd_used;
            if (even_used >= 0 && even_used <= even_count) {
                possible = true;
                break;
            }
        }

        cout << (possible ? "Yes" : "No") << endl;
    }

    return 0;
}
