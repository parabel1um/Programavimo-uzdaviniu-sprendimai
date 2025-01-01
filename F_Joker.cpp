#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--) {
        long long n, m, q;
        cin >> n >> m >> q;

        long long min_pos = m, max_pos = m; // Joker's initial position
        vector<long long> results;

        for (int i = 0; i < q; ++i) {
            long long a_i;
            cin >> a_i;

            // Update the range based on the position of a_i
            if (a_i < min_pos) {
                // Moving a_i to the front
                min_pos--;
            } else if (a_i > max_pos) {
                // Moving a_i to the back
                max_pos++;
            } else if (a_i == min_pos || a_i == max_pos) {
                // If a_i is at the current min or max position
                // Moving it to the front or back does not change the range
                // but we need to adjust the range
                if (a_i == min_pos) {
                    min_pos--;
                } else {
                    max_pos++;
                }
            }

            // Calculate the number of distinct positions
            long long distinct_positions = max_pos - min_pos + 1;
            results.push_back(distinct_positions);
        }

        // Output results for the current test case
        for (long long res : results) {
            cout << res << " ";
        }
        cout << '\n';
    }

    return 0;
}