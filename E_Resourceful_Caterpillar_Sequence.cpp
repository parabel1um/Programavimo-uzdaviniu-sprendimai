#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> degree(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        
        // Read the tree edges and build the graph
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        // Count the number of leaf nodes
        int leaf_count = 0;
        for (int i = 1; i <= n; ++i) {
            if (degree[i] == 1) {
                leaf_count++;
            }
        }

        // Total pairs (p, q) where p ≠ q
        long long total_pairs = (long long) n * (n - 1);

        // Pairs where Aron wins: Aron wins when q is a leaf
        // Count how many pairs (p, q) where q is a leaf and p ≠ q
        long long aron_wins = (long long) leaf_count * (n - 1);

        // Output the result for this test case
        cout << aron_wins << endl;
    }

    return 0;
}
