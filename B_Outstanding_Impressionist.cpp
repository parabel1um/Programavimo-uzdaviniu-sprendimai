#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<pair<pair<int, int>, int>> impressions(n); // (li, ri, index)
        
        for (int i = 0; i < n; ++i) {
            int l, r;
            cin >> l >> r;
            impressions[i] = {{l, r}, i};
        }
        
        // Sort by the left endpoint, and then by the right endpoint
        sort(impressions.begin(), impressions.end());
        
        vector<int> result(n, 0);
        set<int> used; // To keep track of used values
        int current_value = 1; // Start assigning from 1
        
        for (const auto& impression : impressions) {
            int l = impression.first.first;
            int r = impression.first.second;
            int index = impression.second;
            
            // Find the first available value in the range [l, r]
            while (current_value < l) {
                current_value++;
            }
            
            if (current_value <= r) {
                // We can assign this value
                used.insert(current_value);
                result[index] = 1; // This impression can be unique
                current_value++; // Move to the next value for the next impression
            }
        }
        
        // Output the result for this test case
        for (int i = 0; i < n; ++i) {
            cout << result[i];
        }
        cout << '\n';
    }
    
    return 0;
}