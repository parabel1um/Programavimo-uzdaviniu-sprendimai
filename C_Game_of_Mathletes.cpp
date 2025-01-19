#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> x(n);
        unordered_map<int, int> count;

        for (int i = 0; i < n; ++i) {
            cin >> x[i];
            count[x[i]]++;
        }

        int score = 0;

        for (int i = 0; i < n; ++i) {
            int a = x[i];
            int b = k - a;

            if (count[a] > 0 && count[b] > 0) {
                if (a == b) {
                    score += count[a] / 2;
                    count[a] = 0;
                } else {
                    int pairs = min(count[a], count[b]);
                    score += pairs;
                    count[a] -= pairs;
                    count[b] -= pairs;
                }
            }
        }

        cout << score << endl;
    }

    return 0;
}