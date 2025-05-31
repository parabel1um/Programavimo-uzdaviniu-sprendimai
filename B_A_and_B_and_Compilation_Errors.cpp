#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> a(n), b(n-1), c(n-2);
    map<int,int> freq;
    
    // Read arrays and count frequencies
    for(int i=0;i<n;i++) {
        cin>>a[i];
        freq[a[i]]++;
    }
    for(int i=0;i<n-1;i++) {
        cin>>b[i];
        freq[b[i]]--;
    }
    
    // First missing number is the one with frequency 1
    for(auto p : freq) {
        if(p.second == 1) {
            cout << p.first << endl;
            break;
        }
    }
    
    // Reset map for second comparison
    freq.clear();
    for(int i=0;i<n-1;i++) {
        freq[b[i]]++;
    }
    for(int i=0;i<n-2;i++) {
        cin>>c[i];
        freq[c[i]]--;
    }
    
    // Second missing number is the one with frequency 1
    for(auto p : freq) {
        if(p.second == 1) {
            cout << p.first << endl;
            break;
        }
    }
    return 0;
}
