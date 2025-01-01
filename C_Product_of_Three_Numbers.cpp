#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;


    while (n--) {
        bool rasta = false;

        int t, a = -1, b = -1, c = -1;
        cin >> t;

        for (int e = 2; e * e <= t && !rasta; e++) {
            if (t % e == 0) {
                a = e;
                int liek = t / e;
                for (int j = e + 1; j * j <= liek && !rasta; j++) {
                    if (liek % j == 0) {
                        b = j;
                        c = liek / j;
                        if (c > j && c != a && c != b) {
                            rasta = true;
                        }
                    }
                }
            }
        }


    if (rasta) {
        cout << "YES" << endl;
        cout << a << " " << b << " " << c << endl;
    } else {
        cout << "NO" << endl;
    }           
}
}