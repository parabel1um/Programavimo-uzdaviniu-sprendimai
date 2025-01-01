#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int kair = 0, des = 0, sum = 0, maz = 0;

    for (int i = 0; i < k; i++) {
        sum += a[i];
    }

    maz = sum;

    int u = k - 1;

    for (int i = k; i < a.size(); i++) {
        sum += a[i] - a[i - k];
        
        if (maz > sum) {
            maz = sum;
            u = i;
        }
    }

    cout << u - k + 2 << endl;

}