#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<vector<int>> matrix(n, vector<int>(m));
        vector<vector<int>> count(n, vector<int>(k + 1, 0));
        vector<int> unfilled(n, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
                if (matrix[i][j] == -1) {
                    unfilled[i]++;
                } else {
                    count[i][matrix[i][j]]++;
                }
            }
        }
        
        // Fill the unfilled cells optimally
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (unfilled[i] > 0) {
                    count[i][j] += unfilled[i] / k;
                    unfilled[i] -= unfilled[i] / k;
                }
            }
        }
        
        // Calculate the beauty
        long long beauty = 0;
        for (int u = 1; u <= k; ++u) {
            for (int i = 0; i < n - 1; ++i) {
                beauty += (long long)count[i][u] * count[i + 1][u];
            }
        }
        
        cout << beauty << "\n";
    }
    
    return 0;
}