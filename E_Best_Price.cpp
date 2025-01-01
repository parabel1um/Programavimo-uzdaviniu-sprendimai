#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Create a list of potential prices
        vector<int> prices;
        for (int i = 0; i < n; ++i) {
            prices.push_back(a[i]);
            prices.push_back(b[i]);
        }

        // Sort prices to evaluate them in order
        sort(prices.begin(), prices.end());
        prices.erase(unique(prices.begin(), prices.end()), prices.end());

        long long max_earnings = 0;

        // Evaluate each unique price
        for (int price : prices) {
            int positive_count = 0;
            int negative_count = 0;

            for (int i = 0; i < n; ++i) {
                if (price <= a[i]) {
                    positive_count++;
                } else if (price <= b[i]) {
                    negative_count++;
                }
            }

            // If we can afford the negative reviews
            if (negative_count > k) {
                negative_count = k; // Limit to k negative reviews
            }

            long long earnings = (positive_count + negative_count) * price;
            max_earnings = max(max_earnings, earnings);
        }

        cout << max_earnings << endl;
    }

    return 0;
}