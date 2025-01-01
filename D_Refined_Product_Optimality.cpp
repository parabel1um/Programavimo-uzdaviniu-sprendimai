#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 998244353;

long long calculate_product(const std::vector<int>& a, const std::vector<int>& b) {
    long long product = 1;
    for (size_t i = 0; i < a.size(); ++i) {
        product = (product * std::min(a[i], b[i])) % MOD;
    }
    return product;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        int n, q;
        std::cin >> n >> q;
        
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
        }
        
        // Sort both arrays initially
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        
        // Calculate initial product
        long long current_product = calculate_product(a, b);
        std::vector<long long> results;
        results.push_back(current_product);
        
        // Process each operation
        for (int i = 0; i < q; ++i) {
            int o, x;
            std::cin >> o >> x;
            if (o == 1) {
                a[x - 1] += 1; // Increase a[x-1]
            } else {
                b[x - 1] += 1; // Increase b[x-1]
            }
            
            // Sort the modified array
            if (o == 1) {
                std::sort(a.begin(), a.end());
            } else {
                std::sort(b.begin(), b.end());
            }
            
            // Recalculate product after modification
            current_product = calculate_product(a, b);
            results.push_back(current_product);
        }
        
        // Output results for this test case
        for (const auto& res : results) {
            std::cout << res << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}