#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isStable(const vector<int>& segment) {
    if (segment.size() < 3) return true;
    int max_length = *max_element(segment.begin(), segment.end());
    int sum = 0;
    for (int length : segment) {
        sum += length;
    }
    return (max_length < sum - max_length);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool hasDistinct = false;
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[i - 1]) {
                hasDistinct = true;
                break;
            }
        }

        if (!hasDistinct) {
            cout << "YES" << endl;
            continue;
        }

        bool canPartition = false;

        for (int i = 0; i < n - 2; ++i) {
            if (isStable({a[i], a[i + 1], a[i + 2]})) {
                canPartition = true;
                break;
            }
        }

        if (canPartition) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}