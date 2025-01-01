#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        
        set<int> known_questions;
        for (int i = 0; i < k; ++i) {
            int q;
            cin >> q;
            known_questions.insert(q);
        }
        
        string result;
        for (int i = 0; i < m; ++i) {
            int missing_question = a[i];
            if (known_questions.size() == n - 1 && known_questions.find(missing_question) == known_questions.end()) {
                result += '1';
            } else if (known_questions.size() == n) {
                result += '1';
            } else {
                result += '0';
            }
        }
        
        cout << result << '\n';
    }
    
    return 0;
}