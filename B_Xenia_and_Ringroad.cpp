#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int m, n, prev = 1;
    long long sum = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int a;
        cin >> a;
        if (a >= prev) {
            sum += a - prev;
        } else if (a < prev) {
            sum += n - prev + a;
        };
        prev = a;
    }

    cout << sum;
}