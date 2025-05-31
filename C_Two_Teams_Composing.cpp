#include <iostream>
#include <map>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        map<int, int> freq;
        for(int i=0; i<n; i++) {
            int x; cin>>x;
            freq[x]++;
        }
        int distinct = freq.size();
        int max_freq = 0;
        for(auto p : freq) {
            max_freq = max(max_freq, p.second);
        }
        cout << max(min(max_freq - 1, distinct), min(max_freq, distinct - 1)) << endl;
    }
    return 0;
}