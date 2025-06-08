#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a[200005]; cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        bool o=true;
        for (int i=2;i<n;i++) {
            if (a[i-1] < 0) {
                o = false;
                break;
            }
            int k=a[i-1];
            a[i]-=2*k;
            a[i+1]-=k;
        }

        if (a[n]!=0||a[n-1]!=0) o=false;
        cout << (o?"YES":"NO") << endl;
    }
    return 0;
}
