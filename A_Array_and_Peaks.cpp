#include <bits/stdc++.h>
#define ll long_long
#define ft first
#define sc second
#define mp make_pair
#define pb push_back
using namespace std;
int main () {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (k>(n-1)/2) {
            cout << "-1"<< endl;
            continue;
        }
        int i = 1, u=0, j = 0; //j - kiek kartu buvo rasta virsune, i - dabartinis masyvo eiles skaicius, u - elemnto eiles numeris
        while(u<n) {
            if (u%2!=0 && j < k) {
                cout << n - j << " ";
                j++; // didinam rastu virsuniu kieki
            } else {
                cout << i << " ";
                i++;
            }
            u++;
        }
        cout << endl;
    }
}