#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n; cin>>n;
        string s; cin>>s;        
        int k=0;
        for(int i=0;i<n-2;i++) {
            if(s.substr(i, 3)=="map"||s.substr(i, 3)=="pie") {
                k++;
                i+=2;
            }
        }
        cout<<k<<endl;
    }
    return 0;
}