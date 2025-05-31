#include <iostream>
#include <vector>
using namespace std;
int main() {
    string s; cin>>s;
    int m; cin>>m;
    vector<int> a(s.length(), 0);    
    for(int i = 0; i < s.length()-1; i++) a[i+1] = a[i] + (s[i] == s[i+1]);
    for(int i = 0; i < m; i++) {
        int l, r; cin>>l>>r;
        cout << a[r-1] - a[l-1] << endl;
    }
}