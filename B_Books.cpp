#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int kair = 0, des = 0, sum = 0, daug = 0;

    while (des < n) {
        sum += a[des];
        while (sum > t) {
            sum -= a[kair];
            kair++;
        }
        des++;
        daug = max(daug, des - kair);
    }

    cout << daug << endl;

    return 0;
}
