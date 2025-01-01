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
        int n;
        long long x, y;
        cin >> n >> x >> y;
        
        vector<long long> a(n);
        long long total_sum = 0;
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            total_sum += a[i];
        }
        
        long long L = total_sum - y;
        long long U = total_sum - x;
        
        sort(a.begin(), a.end());
        
        long long count = 0;
        
        for (int i = 0; i < n; ++i) {
            long long target = L - a[i];
            int left = lower_bound(a.begin() + i + 1, a.end(), target) - a.begin();
            target = U - a[i];
            int right = upper_bound(a.begin() + i + 1, a.end(), target) - a.begin();
            
            count += (right - left);
        }
        
        cout << count << '\n';
    }
    
    return 0;
}