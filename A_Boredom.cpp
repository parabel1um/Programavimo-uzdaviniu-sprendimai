#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;  // Number of elements in the sequence
    cin >> n;  // Read the number of elements

    vector<int> a(n);  // Array to hold the sequence of numbers
    int max_val = 0;  // Variable to track the maximum number in the sequence
    for (int i = 0; i < n; ++i) {
        cin >> a[i];  // Read each element of the sequence
        max_val = max(max_val, a[i]);  // Update the maximum value
    }

    vector<long long> freq(max_val + 1, 0);  // Frequency array to count occurrences of each number
    for (int i = 0; i < n; ++i) {
        freq[a[i]]++;  // Increment the frequency of the number a[i]
    }

    vector<long long> dp(max_val + 1, 0);  // DP array to store the maximum points up to each number
    dp[1] = freq[1] * 1;  // Base case: if we only have 1's, the score is freq[1] * 1

    for (int i = 2; i <= max_val; ++i) {
        // We can either:
        // 1. Skip the current number i: dp[i-1]
        // 2. Take the current number i: dp[i-2] + freq[i] * i
        dp[i] = max(dp[i-1], dp[i-2] + freq[i] * i);
    }

    cout << dp[max_val] << endl;  // Output the maximum score possible
    return 0;
}
