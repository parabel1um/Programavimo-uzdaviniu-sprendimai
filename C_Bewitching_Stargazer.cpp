#include <iostream>
#include <vector>
using namespace std;

long long calculateLuckyValue(long long n, long long k) {
    long long luckyValue = 0;

    // Start with the full range [1, n]
    long long l = 1, r = n;

    // While the segment length is at least k
    while (r - l + 1 >= k) {
        long long length = r - l + 1;
        long long mid = (l + r) / 2; // Middle index

        // If the length is odd, add the middle value to luckyValue
        if (length % 2 == 1) {
            luckyValue += mid;
        }

        // Split the segments
        if (length % 2 == 0) {
            // If length is even, create an array of stars from l to r
            vector<int> stars;
            for (int i = l; i <= r; i++) {
                stars.push_back(i);
            }

            // You can now use the 'stars' vector as needed
            // For example, you can print it
            cout << "Stars in the segment [" << l << ", " << r << "]: ";
            for (int star : stars) {
                cout << star << " ";
            }
            cout << endl;

            // Continue with the left segment
            r = mid; // New segment is [l, mid]
        } else {
            // If length is odd, we continue with the right segment
            l = mid + 1; // New segment is [mid + 1, r]
        }
    }

    return luckyValue;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;
        cout << calculateLuckyValue(n, k) << "\n";
    }

    return 0;
}