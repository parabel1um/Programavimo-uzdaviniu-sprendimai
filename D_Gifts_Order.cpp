#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_convenience(const vector<int>& a) {
    int n = a.size();
    int max_convenience_value = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sub_max = *max_element(a.begin() + i, a.begin() + j + 1);
            int sub_min = *min_element(a.begin() + i, a.begin() + j + 1);
            int convenience = sub_max - sub_min - (j - i);
            max_convenience_value = max(max_convenience_value, convenience);
        }
    }

    return max_convenience_value;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        cout << max_convenience(a) << endl;

        for (int i = 0; i < q; i++) {
            int p, x;
            cin >> p >> x;
            a[p - 1] = x;
            cout << max_convenience(a) << endl;
        }
    }

    return 0;
}