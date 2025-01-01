#include <iostream>

using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;

    long long ilgis = (n + a - 1) / a; // ceil function of n / a
    long long plotis = (m + a - 1) / a;

    cout << ilgis * plotis << endl;

    return 0;
}