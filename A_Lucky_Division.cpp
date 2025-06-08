#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    for (int i=1;i<=n;++i) {
        bool o=true;
        int k=i;
        while (k>0) {
            int d=k%10;
            if (d!=4&&d!=7) {
                o=false;
                break;
            }
            k/=10;
        }
        if (o&&n%i == 0) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
