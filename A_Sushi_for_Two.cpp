#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n;i++) cin >> a[i];
    vector<int> gr;
    int k=1;
    for(int i=1;i<n;i++) {
        if(a[i] == a[i-1]) {
            k++;
        } else {
            gr.push_back(k);
            k = 1;
        }
    }
    gr.push_back(k);
    int ans = 0;
    for(int i = 0; i < gr.size()-1; i++) {
        ans = max(ans, 2*min(gr[i], gr[i+1]));
    }    
    cout << ans << endl;
    return 0;
}